#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <time.h>
#include <string>

#define TRUE 1
#define DS_TEST_PORT 68000

#pragma comment (lib, "ws2_32.lib")
#pragma warning(disable : 4996)

HANDLE ghMutex;

typedef struct _CHAVE
{
	int numeros[5];
	int estrelas[2];

}CHAVE;

typedef struct _LIST_NODE
{
	void* data;
	struct _LIST_NODE* next;
}LIST_NODE;

typedef LIST_NODE* LIST;

#define DATA(node) ((node)->data)
#define NEXT(node) ((node)->next)

// função para coordenar a conexao do cliente
DWORD WINAPI handleconnection(LPVOID lpParam);
LIST_NODE* NewNode(void* data);
void InsertEnd(LIST* list, void* data);
void WriteChaves(LIST list);
bool Existe(int* numeros, int quantosNumeros, int valor);
void Aleatorios(int* numeros, int quantosNumeros, int limite);
void Ordenar(int* numeros, int quantosNumeros);
int CountChaves(const char* filename);
void ReadChaves(LIST* list, const char* filename);
void RemoveFirst(LIST* list);
void FreeList(LIST* list);
bool ExisteChave(int* numeros, int* estrelas, LIST chaves);

using namespace std;

int main()
{
	// Initialise winsock
	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);

	printf("\nInitialising Winsock...");
	int wsResult = WSAStartup(ver, &wsData);

	if (wsResult != 0) {
		fprintf(stderr, "\nWinsock setup fail! Error Code : %d\n", WSAGetLastError());
		return 1;
	}

	//Create a mutex with no initial owner
	ghMutex = CreateMutex(
		NULL,              // default security attributes
		FALSE,             // initially not owned
		NULL);             // unnamed mutex

	if (ghMutex == NULL)
	{
		printf("CreateMutex error: %d\n", GetLastError());
		return 1;
	}

	// Create a socket
	//server socket
	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET) {
		fprintf(stderr, "\nSocket creationg fail! Error Code : %d\n", WSAGetLastError());
		return 1;
	}

	printf("\nSocket created.");

	// Bind the socket (ip address and port)
	struct sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(DS_TEST_PORT);
	hint.sin_addr.S_un.S_addr = INADDR_ANY;

	//da mesma maneira que se faz o connect no cliente
	//associar um socket a um ip e porto
	bind(listening, (struct sockaddr*)&hint, sizeof(hint));

	// Setup the socket for listening
	//segundo paramentro representa quantas conexoes podem estar a espera deste socket
	listen(listening, SOMAXCONN);

	// Wait for connection
	struct sockaddr_in client;
	int clientSize = sizeof(client);
	SOCKET clientSocket;
	SOCKET* ptclientSocket;
	DWORD dwThreadId;
	HANDLE hThread;
	int countresult = 0;

	while (TRUE)
	{
		clientSize = sizeof(client);
		clientSocket = accept(listening, (struct sockaddr*)&client, &clientSize);
		ptclientSocket = &clientSocket;

		printf("\nHandling a new connecction\n");

		hThread = CreateThread(NULL, 0, handleconnection, ptclientSocket, 0, &dwThreadId);
		if (hThread == NULL)
		{
			printf("\nThread creation error");
			ExitProcess(3);
		}
	}

	CloseHandle(ghMutex);

	// Close socket
	closesocket(clientSocket);

	// Close listening socket
	closesocket(listening);

	// Clean up winsocks
	WSACleanup();

}

DWORD WINAPI handleconnection(LPVOID lpParam)
{
	// Main program loop

	char strMsg[1024];
	char strRec[1024];
	LIST chaves = NULL;
	LIST chavesAux = NULL;

	SOCKET cs;
	SOCKET* ptCs;

	ptCs = (SOCKET*)lpParam;
	cs = *ptCs;

	DWORD dwWaitResult;

	//Envia 100 OK
	strcpy(strMsg, "\n100 OK\n");
	send(cs, strMsg, strlen(strMsg) + 1, 0);

	printf("\n\nServer...\n\n");

	//Recebe comando para jogar
	ZeroMemory(strRec, 1024);
	recv(cs, strRec, 1024, 0);

	if (strcmp(strRec, "Chaves") == 0) {

		LIST enviarChaves = NULL;

		ZeroMemory(strMsg, 1024);
		
		//Mutex para ler as chaves do ficheiro
		dwWaitResult = WaitForSingleObject(
			ghMutex,    // handle to mutex
			INFINITE);  // no time-out interval

		switch (dwWaitResult)
		{
			// The thread got ownership of the mutex
		case WAIT_OBJECT_0:
			__try {
				ReadChaves(&enviarChaves, "chaves.txt");
			}

			__finally {
				// Release ownership of the mutex object
				if (ReleaseMutex(ghMutex) != 0)
				{
					printf("hMutex handle was released!\n");
				}
				else
				{
					printf("Failed to release the hMutex handle, error % u\n", GetLastError());
				}
			}
			break;

			// The thread got ownership of an abandoned mutex
			// The database is in an indeterminate state
		case WAIT_ABANDONED:
			return FALSE;
		}

		int numerosAux[5] = {};
		int estrelasAux[2] = {};
		int totalChaves = CountChaves("Chaves.txt");

		//Envia o numero total de chaves, para o cliente usar no ciclo for
		send(cs, (char*)&totalChaves, sizeof(totalChaves), 0);

		int i = 0;

		while (enviarChaves != NULL)
		{
			for (i = 0; i < 5; i++) {
				numerosAux[i] = ((CHAVE*)enviarChaves->data)->numeros[i];
			}

			for (i = 0; i < 2; i++) {
				estrelasAux[i] = ((CHAVE*)enviarChaves->data)->estrelas[i];
			}

			//Envia numeros
			send(cs, (char*)numerosAux, sizeof(numerosAux), 0);
			//Envia estrelas
			send(cs, (char*)estrelasAux, sizeof(estrelasAux), 0);

			enviarChaves = enviarChaves->next;
		}

	}


	if (strcmp(strRec, "Entrar") == 0)
	{

		//Mutex para ler as chaves do ficheiro
		dwWaitResult = WaitForSingleObject(
			ghMutex,    // handle to mutex
			INFINITE);  // no time-out interval

		switch (dwWaitResult)
		{
			// The thread got ownership of the mutex
		case WAIT_OBJECT_0:
			__try {
				ReadChaves(&chavesAux, "chaves.txt");
			}

			__finally {
				// Release ownership of the mutex object
				if (ReleaseMutex(ghMutex) != 0)
				{
					printf("hMutex handle was released!\n");
				}
				else
				{
					printf("Failed to release the hMutex handle, error % u\n", GetLastError());
				}
			}
			break;

			// The thread got ownership of an abandoned mutex
			// The database is in an indeterminate state
		case WAIT_ABANDONED:
			return FALSE;
		}

		while (TRUE) {

			//Recebe o numero de chaves	para enviar
			ZeroMemory(strRec, 1024);
			int bytesReceived = recv(cs, strRec, 1024, 0);

			if (bytesReceived == SOCKET_ERROR) {
				printf("\nReceive error!\n");
				break;
			}

			int i = 0;
			int j = 0;

			for (j = 0; j < (int)strRec[0]; j++) {

				ZeroMemory(strMsg, 1024);

				int numero[5] = {};
				int sizeNumeros = sizeof(numero) / sizeof(numero[0]);
				int estrelas[2] = {};
				int sizeEstrelas = sizeof(estrelas) / sizeof(estrelas[0]);

				//Enquanto ExisteChave retornar true (chave existe) vai criar uma chave nova
				do {
					Aleatorios(numero, 5, 50);
					Ordenar(numero, sizeNumeros);

					Aleatorios(estrelas, 2, 12);
					Ordenar(estrelas, sizeEstrelas);

				} while (ExisteChave(numero, estrelas, chavesAux) == true);

				printf("Numeros enviados: ");
				for (i = 0; i < 5; i++)
				{
					printf(" %d", numero[i]);
				}

				printf("\t");

				printf("\nEstrelas enviadas: ");
				for (i = 0; i < 2; i++)
				{
					printf(" %d", estrelas[i]);
				}

				printf("\n");

				time_t now = time(0);
				char* dt = ctime(&now);
				strcpy(strMsg, dt);

				//Envia a data, numeros e estrelas
				send(cs, strMsg, strlen(strMsg), 0);
				send(cs, (char*)numero, sizeof(numero), 0);
				send(cs, (char*)estrelas, sizeof(estrelas), 0);

				CHAVE* ch;

				//Cria a nova chave
				if ((ch = (CHAVE*)malloc(sizeof(CHAVE))) != NULL)
				{
					int k = 0;

					for (k = 0; k < 5; k++)
					{
						ch->numeros[k] = numero[k];
					}

					for (k = 0; k < 2; k++)
					{
						ch->estrelas[k] = estrelas[k];
					}
				//Insire na lista das chaves
				InsertEnd(&chaves, ch);

				}

				Sleep(200);

			}

			//Mutex para escrever as chaves no ficheiro
			dwWaitResult = WaitForSingleObject(
				ghMutex,    // handle to mutex
				INFINITE);  // no time-out interval

			switch (dwWaitResult)
			{
				// The thread got ownership of the mutex
			case WAIT_OBJECT_0:
				__try {
					WriteChaves(chaves);
				}

				__finally {
					// Release ownership of the mutex object
					if (ReleaseMutex(ghMutex) != 0)
					{
						printf("hMutex handle was released!\n");
					}
					else
					{
						printf("Failed to release the hMutex handle, error % u\n", GetLastError());
					}
				}
				break;

				// The thread got ownership of an abandoned mutex
				// The database is in an indeterminate state
			case WAIT_ABANDONED:
				return FALSE;
			}

			char countBuffer[20] = "";
			//Converte o numero de chaves total para char 
			itoa(CountChaves("Chaves.txt"), countBuffer, 10);

			//Enviar o numero total de chaves 
			send(cs, countBuffer, strlen(countBuffer), 0);

			FreeList(&chaves);

			//Recebe o Quit
			ZeroMemory(strRec, 1024);
			recv(cs, strRec, 1024, 0);


			if (strcmp(strRec, "quit") == 0 || strcmp(strRec, "Quit") == 0) {
				ZeroMemory(strMsg, 1024);
				strcpy(strMsg, "\n400 bye\n");
				printf("Client disconected");
				send(cs, strMsg, strlen(strMsg) + 1, 0);
			}
		}
	}

	if (strcmp(strRec, "Quit") == 0) {
		ZeroMemory(strMsg, 1024);
		strcpy(strMsg, "\n400 bye\n");
		printf("Client disconected");
		send(cs, strMsg, strlen(strMsg) + 1, 0);

		return 0;
	}

}


bool Existe(int* numeros, int quantosNumeros, int valor) {
	for (int i = 0; i < quantosNumeros; i++)
	{
		if (*(numeros + i) == valor) {
			return true;
		}
	}
	return false;
}

void Aleatorios(int* numeros, int quantosNumeros, int limite) {

	srand(time(NULL) + rand());

	int valor;

	for (int i = 0; i < quantosNumeros; i++)
	{
		valor = rand() % limite + 1;
		while (Existe(numeros, i, valor)) {
			valor = rand() % limite + 1;
		}

		*(numeros + i) = valor;
	}
}

void Ordenar(int* numeros, int quantosNumeros) {
	int i;
	int j;

	for (i = 0; i < quantosNumeros; i++) {
		for (j = 0; j < quantosNumeros; j++) {
			if (*(numeros + j) > *(numeros + i)) {
				int aux = *(numeros + j);
				*(numeros + j) = *(numeros + i);
				*(numeros + i) = aux;
			}
		}
	}
}

LIST_NODE* NewNode(void* data)
{
	LIST_NODE* new_node;
	if ((new_node = (LIST_NODE*)malloc(sizeof(LIST_NODE))) != NULL)
	{
		DATA(new_node) = data;
		NEXT(new_node) = NULL;
	}
	return(new_node);
}

void InsertEnd(LIST* list, void* data)
{
	LIST_NODE* new_node, * temp;
	if ((new_node = NewNode(data)) != NULL)
	{
		if (*list == NULL)
			*list = new_node;
		else
		{
			temp = *list;
			while (NEXT(temp) != NULL)
				temp = NEXT(temp);
			NEXT(temp) = new_node;
		}
		return;
	}
	printf("Erro ao adicioar no a lista");
}

void WriteChaves(LIST list)
{
	FILE* fp;
	int i = 0;

	if ((fp = fopen("chaves.txt", "a")) == NULL)
	{
		printf("Erro");
	}

	while (list != NULL)
	{
		//fprintf(fp, "Numeros: ");

		for (i = 0; i < 5; i++) {
			fprintf(fp, "%d;", ((CHAVE*)DATA(list))->numeros[i]);
		}

		//fprintf(fp, "  Estrelas: ");

		for (i = 0; i < 2; i++) {
			fprintf(fp, "%d;", ((CHAVE*)DATA(list))->estrelas[i]);
		}

		fprintf(fp, "\n");

		list = list->next;
	}
	fclose(fp);
}

int CountChaves(const char* filename) {

	FILE* fp;

	int count = 0;

	char chr;

	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("Erro");
	}

	while (!feof(fp))
	{
		chr = fgetc(fp);
		if (chr == '\n')
		{
			count++;
		}
	}
	fclose(fp);

	return count;
}


void ReadChaves(LIST* list, const char* filename)
{
	CHAVE* data;
	FILE* fp;
	char aux[20];
	char aux2[20];

	if ((fp = fopen(filename, "r")) == NULL) {
		return;
	}


	while (!feof(fp))
	{
		if (((data = (CHAVE*)malloc(sizeof(CHAVE))) != NULL))
		{
			InsertEnd(list, data);

			/*for (int i = 0; i < 5; i++)
			{*/
			fscanf_s(fp, "%d;%d;%d;%d;%d;%d;%d;\n", &(data->numeros[0]),
				&(data->numeros[1]), &(data->numeros[2]),
				&(data->numeros[3]), &(data->numeros[4]),
				&(data->estrelas[0]), &(data->estrelas[1]));
			/*	}*/


		}
		else
			return;
	}
	fclose(fp);

	return;
}

bool ExisteChave(int* numeros, int* estrelas, LIST chaves)
{
	int i = 0;
	int count = 0;

novo:
	while (chaves != NULL)
	{
		for (i = 0; i < 5; i++)
		{

			if (((CHAVE*)DATA(chaves))->numeros[i] == numeros[i]) {
				count++;
			}

		}

		if (count != 5) {
			chaves = NEXT(chaves);
			goto novo;
		}

		count = 0;

		for (i = 0; i < 2; i++)
		{
			if (((CHAVE*)DATA(chaves))->estrelas[i] == estrelas[i]) {
				count++;
			}
		}

		if (count == 2) {
			return true;
		}

		chaves = NEXT(chaves);

	}

	return false;
}

void RemoveFirst(LIST* list) {

	LIST_NODE* node;

	node = NEXT(*list);
	free(DATA(*list));
	free(*list);
	*list = node;
}

void FreeList(LIST* list) {
	while (*list != NULL)
	{
		RemoveFirst(list);
	}
}
