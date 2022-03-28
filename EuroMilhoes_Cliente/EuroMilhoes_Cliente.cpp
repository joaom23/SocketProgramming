#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<winsock2.h>
#include <conio.h>
#include <string>

#pragma comment(lib,"ws2_32.lib") 
#pragma warning(disable : 4996)

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

#define ch1 179
#define ch2 191
#define ch3 192
#define ch4 196
#define ch5 217
#define ch6 218
#define ch7 195
#define ch8 47
#define ch9 92
#define ch10 186
#define ch11 187
#define ch12 188
#define ch13 200
#define ch14 201
#define ch15 205
#define ch16 219
#define ch17 202
#define ch18 203

//#define IP "127.0.0.1"
#define IP "25.64.35.196"

void MenuPrincipal();
int Cliente(char es);
void printCirculo(int* numero);
void printEstrela(int* estrela);

int main() {
	MenuPrincipal();
}

void MenuPrincipal() {
	SetConsoleTextAttribute(hConsole, 3);
	char es = '0';

	printf("\n");
	printf("\n");
	printf("                 %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", ch14, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch11);
	printf("                 %c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c\n", ch10, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c\n", ch10, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c\n", ch10, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c %c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c %c\n", ch10, ch16, ch16, ch16, ch16, ch16, ch14, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch11, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c %c%c%c%c%c %c      ######  ######  ######  #       #  #####  ######    #######    ######                       %c %c%c%c%c%c %c         \n", ch10, ch16, ch16, ch16, ch16, ch16, ch10, ch10, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c %c%c%c%c%c %c     #        #       #     #  #     #     #    #     #   #     #    #     #                      %c %c%c%c%c%c %c             \n", ch10, ch16, ch16, ch16, ch16, ch16, ch10, ch10, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c %c%c%c%c%c %c       ##     ######  ######    #   #      #    #      #  #     #    ######                       %c %c%c%c%c%c %c                \n", ch10, ch16, ch16, ch16, ch16, ch16, ch10, ch10, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c %c%c%c%c%c %c        #     #       # #        # #       #    #     #   #     #    # #                          %c %c%c%c%c%c %c               \n", ch10, ch16, ch16, ch16, ch16, ch16, ch10, ch10, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c %c%c%c%c%c %c   #####      ######  #  #        #      #####  ######    #######    #  #                         %c %c%c%c%c%c %c                \n", ch10, ch16, ch16, ch16, ch16, ch16, ch10, ch10, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c %c%c%c%c%c %c                                                                                                  %c %c%c%c%c%c %c                  \n", ch10, ch16, ch16, ch16, ch16, ch16, ch10, ch10, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c %c%c%c%c%c %c              ######  #    #	    #      #       #  ######  #####                                 %c %c%c%c%c%c %c                \n", ch10, ch16, ch16, ch16, ch16, ch16, ch10, ch10, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c %c%c%c%c%c %c              #       #    #     # #      #     #   #       #                                     %c %c%c%c%c%c %c             \n", ch10, ch16, ch16, ch16, ch16, ch16, ch10, ch10, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c %c%c%c%c%c %c              #       ######    #####      #   #    ######    ##                                  %c %c%c%c%c%c %c                 \n", ch10, ch16, ch16, ch16, ch16, ch16, ch10, ch10, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c %c%c%c%c%c %c              #       #    #   #     #      # #     #           #                                 %c %c%c%c%c%c %c                  \n", ch10, ch16, ch16, ch16, ch16, ch16, ch10, ch10, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c %c%c%c%c%c %c              ######  #    #  #       #      #      ######  #####                                 %c %c%c%c%c%c %c               \n", ch10, ch16, ch16, ch16, ch16, ch16, ch10, ch10, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c %c%c%c%c%c %c                                                                                                  %c %c%c%c%c%c %c                 \n", ch10, ch16, ch16, ch16, ch16, ch16, ch10, ch10, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c %c%c%c%c%c %c   ######    #     #  ######   #######  ##   ##  #####  #     #    #  #######  ######     ######  %c %c%c%c%c%c %c               \n", ch10, ch16, ch16, ch16, ch16, ch16, ch10, ch10, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c %c%c%c%c%c %c   #         #     #  #     #  #     #  # # # #    #    #     #    #  #     #  #         #        %c %c%c%c%c%c %c                \n", ch10, ch16, ch16, ch16, ch16, ch16, ch10, ch10, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c %c%c%c%c%c %c   ######    #     #  ######   #     #  #  #  #    #    #     ######  #     #  ######     ##      %c %c%c%c%c%c %c                 \n", ch10, ch16, ch16, ch16, ch16, ch16, ch10, ch10, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c %c%c%c%c%c %c   #         #     #  # #      #     #  #     #    #    #     #    #  #     #  #            #     %c %c%c%c%c%c %c                \n", ch10, ch16, ch16, ch16, ch16, ch16, ch10, ch10, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c %c%c%c%c%c %c   ######     #####   #  #     #######  #     #  #####  ####  #    #  #######  ######  #####      %c %c%c%c%c%c %c     \n", ch10, ch16, ch16, ch16, ch16, ch16, ch10, ch10, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c %c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c %c\n", ch10, ch16, ch16, ch16, ch16, ch16, ch13, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch18, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch18, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch12, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c 1 - Entrar %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c\n", ch10, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch10, ch10, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c 2 - Regras %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c\n", ch10, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch10, ch10, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c 3 - Chaves %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c\n", ch10, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch10, ch10, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c 4 - Quit	  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c\n", ch10, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch10, ch10, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch16, ch10);
	printf("                 %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", ch13, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch17, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch17, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch15, ch12);

	SetConsoleTextAttribute(hConsole, 7);
	es = getch();
	while (es != '1' && es != '2' && es != '3' && es != '4')
	{
		printf("\nEscolha uma opcao valida\n");
		Sleep(1000);
		system("cls");
		MenuPrincipal();
		es = getch();
	}

	if (es == '1')
	{
		system("cls");
		Cliente(es);
		system("pause");
		system("cls");

	}
	else if (es == '2')
	{
		system("cls");
		printf("\n\n --> O servidor de chaves euromilhoes, consiste em um servidor fornecer um determinado numero de chaves do euromilhoes de acordo com o numero de chaves que \n");
		printf("o cliente prentenda receber. Note que as chaves recebidas, nunca vao ser repetidas.\n");
		printf("As chaves selecionadas sao cinco números principais de 1 a 50, seguidos dos dois números adicionais das Estrelas da Sorte entre 1 e 12.\n");
		printf("Todos os jogadores devem ter pelo menos 18 anos .\n\n");
		printf("\n\nPressione alguma tecla para voltar ao MenuPrincipal\n");
		system("pause");
		system("cls");
		MenuPrincipal();
	}
	else if (es == '3')
	{
		system("cls");
		Cliente(es);
		printf("\n\nPressione alguma tecla para voltar ao MenuPrincipal\n");
		system("pause");
		system("cls");
		MenuPrincipal();
	}
	else if (es == '4') {
		system("cls");
		exit(0);
	}

	/*return;*/
}

int Cliente(char es)
{
	WSADATA wsa;
	SOCKET s;

	//servidor
	struct sockaddr_in server;
	//char message[] = "GET / HTTP/1.1\r\n\r\n", server_reply[2000];
	char message[2000], server_reply[2000];
	int recv_size;
	int ws_result;

	// Initialise winsock
	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		return 1;
	}

	printf("Initialised.\n");

	//Create a socket
	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s == INVALID_SOCKET)
	{
		printf("Could not create socket : %d", WSAGetLastError());
		return 1;
	}

	printf("Socket created.\n");

	// create the socket  address (ip address and port)
	server.sin_addr.s_addr = inet_addr(IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(68000);

	//Connect to remote server
	ws_result = connect(s, (struct sockaddr*)&server, sizeof(server));

	//Verifica se a conexão foi bem feita
	if (ws_result < 0)
	{
		puts("Nao foi possivel ligar ao servidor, tente mais tarde.\n");
		printf("Pressione alguma tecla para voltar ao MenuPrincipal\n");
		system("pause");
		system("cls");
		MenuPrincipal();
	}

	puts("Connected");
	printf("\n\nCliente...\n\n");

	//Recebe 100 OK
	ZeroMemory(server_reply, 2000);
	recv_size = recv(s, server_reply, 2000, 0);
	puts(server_reply);

	//Caso utilizador escolha comando 3 
	if (es == '3') {

		int numerosAux[5] = {};
		int estrelasAux[2] = {};
		int totalChaves = 0;
		int u = 0;
		int l = 0;

		//Envia o comando 3 (Chaves)
		ZeroMemory(message, 1024);
		strcpy(message, "Chaves");

		send(s, message, strlen(message) + 1, 0);

		//Recebe o numero total das chaves
		ZeroMemory(server_reply, 1024);
		recv(s, server_reply, 1024, 0);

		for (u = 0; u < (int)server_reply[0]; u++) {
			recv_size = recv(s, (char*)numerosAux, 20, 0);
			recv_size = recv(s, (char*)estrelasAux, 8, 0);

			//Print dos numeros 
			printf("Numeros: ");

			for (l = 0; l < 5; l++) {
				printf("%d ", numerosAux[l]);
			}

			//Print das estrelas
			printf(" Estrelas: ");

			for (l = 0; l < 2; l++) {
				printf("%d ", estrelasAux[l]);
			}

			printf("\n");
		}
	}

	//Caso utilizador escolha comando 1
	if (es == '1') {
	jogar:
		
		//Envia o comando 1 (Entrar)
		ZeroMemory(message, 2000);
		strcpy(message, "Entrar");

		send(s, message, strlen(message) + 1, 0);

		char ch[20] = "";
		int count = 0;
		int numChaves = 0;
		int j = 0;
		int i = 0;
		int numeros[5] = {};
		int estrelas[2] = {};

		printf("\nPara voltar ao menu insira \"v\". \n\n");

		printf("Quantas chaves quer?\n");

		if (recv_size == SOCKET_ERROR)
		{
			puts("recv failed");
		}

	erro:
		//Ler o numero de chaves
		scanf("%s", &ch);

		//Se o utilizador enviar "v" volta para o menu
		if (strcmp(ch, "v") == 0 || strcmp(ch, "V") == 0) {
			system("cls");
			MenuPrincipal();
		}
		
		//Verifica se é um numero valido e entre 0 e 101
		for (i = 0; i < strlen(ch); i++) {

			if (isdigit(ch[i]) == 0) {
				printf("Por favor insira um valor numerico.\n");
				goto erro;
			}
			else {
				count++;
			}
			if (count == strlen(ch)) {
				numChaves = atoi(ch);
				if (numChaves > 101 || numChaves <= 0) {
					printf("Insira um numero entre 1 e 100.0\n");
					count = 0;
					goto erro;
				}
			}
		}

		//Envia o numero de chaves que quer
		ws_result = send(s, (char*)&numChaves, 1, 0);

		if (ws_result < 0)
		{
			puts("Erro ao enviar os dados.");
			return 1;
		}

		//numChaves é o numero inserido pelo utilizador
		for (i = 0; i < numChaves; i++) {

			ZeroMemory(server_reply, 2000);

			//Recebe a data
			recv_size = recv(s, server_reply, 2000, 0);
			if (recv_size == SOCKET_ERROR)
			{
				puts("Erro ao reber os dados.");
			}

			//Recebe os numeros
			ZeroMemory((char*)numeros, 20);
			recv_size = recv(s, (char*)numeros, 20, 0);
			if (recv_size == SOCKET_ERROR)
			{
				puts("Erro ao reber os dados.");
			}

			//Recebe as estrelas
			ZeroMemory((char*)estrelas, 8);
			recv_size = recv(s, (char*)estrelas, 8, 0);
			if (recv_size == SOCKET_ERROR)
			{
				puts("Erro ao reber os dados.");
			}

			SetConsoleTextAttribute(hConsole, 11);

			//Print da data
			printf("\nData: ");
			puts(server_reply);

			SetConsoleTextAttribute(hConsole, 7);

			SetConsoleTextAttribute(hConsole, 12);

			//Print dos numeros 
			printf("Numeros recebidos: \n");

			printCirculo(numeros);

			printf("\n");

			SetConsoleTextAttribute(hConsole, 14);

			//Print das estrelas
			printf("Estrelas recebidas: \n");

			printEstrela(estrelas);

			printf("\n\n");

			SetConsoleTextAttribute(hConsole, 7);

		}

		//Recebe o numero total de chaves ja enviadas pelo servidor
		ZeroMemory(server_reply, 2000);
		recv_size = recv(s, server_reply, 2000, 0);
		printf("O servidor ja enviou %s chaves", server_reply);

		//Pergunta ao utilizador se quer pedir mais chaves ou sair para o menu
		printf("\n\nQuer pedir mais chaves? ('S' ou 'N'/ 'Quit')\n");

		ZeroMemory(message, 2000);
		scanf("%s", &message);

		while (strcmp(message, "s") != 0 && strcmp(message, "S") != 0 && strcmp(message, "n") != 0 && strcmp(message, "N") != 0
			&& strcmp(message, "quit") != 0 && strcmp(message, "Quit") != 0) {
			printf("Valor invalido, por favor insira 'S' ou 'N'/'Quit'\n");
			scanf("%s", &message);
		}

		//Se for para jogar de novo volta para "jogar" na linha 229
		if (strcmp(message, "s") == 0 || strcmp(message, "S") == 0) {			
			system("cls");
			goto jogar;
		}
		else if (strcmp(message, "quit") == 0 || strcmp(message, "Quit") == 0 || strcmp(message, "n") == 0 || strcmp(message, "N") == 0) {

			ZeroMemory(message, 2000);
			strcpy(message, "Quit");
			//Envia comando Quit
			send(s, message, strlen(message) + 1, 0);


			system("cls");
			ZeroMemory(server_reply, 2000);
			//Recebe 400 Bye
			recv_size = recv(s, server_reply, 2000, 0);
			puts(server_reply);

			Sleep(2000);
			system("cls");

			MenuPrincipal();
		}
	}

	// Close the socket
	closesocket(s);

	//Cleanup winsock
	WSACleanup();

	return 0;
}

void printCirculo(int* numero) {

	int i = 0;

	for ( i = 0; i < 5; i++)
	{
		printf("\t         ***      \t");
	}

	printf("\n");

	for ( i = 0; i < 5; i++)
	{
		printf("\t      *       *   \t");
	}
	

	printf("\n");

	for ( i = 0; i < 5; i++)
	{
		printf("\t     *         *  \t");
	}

	printf("\n");

	for (i = 0; i < 5; i++)
	{
		if (*(numero + i) > 9) {
			printf("\t    *    %d     * \t", *(numero + i));
		}
		else {
			printf("\t    *     %d     * \t", *(numero + i));
		}

	}

	printf("\n");

	for ( i = 0; i < 5; i++)
	{
		printf("\t     *         *  \t");
	}

	printf("\n");

	for ( i = 0; i < 5; i++)
	{
		printf("\t      *       *   \t");
	}

	printf("\n");

	for ( i = 0; i < 5; i++)
	{
		printf("\t         ***      \t");
	}

	printf("\n");
}

void printEstrela(int* estrela) {

	int i = 0;

	for ( i = 0; i < 2; i++)
	{
		printf("\t\t\t       *        \t");
	}

	printf("\n");

	for ( i = 0; i < 2; i++)
	{
		printf("\t\t\t     *   *      \t");
	}

	printf("\n");

	for (i = 0; i < 2; i++)
	{
		if (*(estrela + i) > 9) {
			printf("\t\t\t *    %d    *   \t", *(estrela + i));
		}
		else {
			printf("\t\t\t *     %d     *  \t", *(estrela + i));
		}

	}

	printf("\n");

	for ( i = 0; i < 2; i++)
	{
		printf("\t\t\t   *      *     \t");
	}

	printf("\n");

	for ( i = 0; i < 2; i++)
	{
		printf("\t\t\t *    *    *    \t");
	}

	printf("\n");

	for ( i = 0; i < 2; i++)
	{
		printf("\t\t\t*   *     *  *  \t");
	}

	printf("\n");

	for ( i = 0; i < 2; i++)
	{
		printf("\t\t\t*            *  \t");
	}

	printf("\n");


}
