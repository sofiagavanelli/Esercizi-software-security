#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//due overflow --> due badfile

int flag = 0;
char str3[20] = "    ";
char str1[20];
char str2[] = "Congratulations you win";
char stringa[260]; //si vuole usare questa: il p va sovrascritto con l'indirizzo di questa stringa

void join_string(char *dst, char *src) {

	printf("join_string\n");
	printf("str1:%s\n", dst);
	printf("str1:%s\n", src);
	printf("str1:%.8x\n", dst);
	printf("str1:%.8x\n", src);

	strcat(dst, src);
	printf("str1:%.8x\n", dst);
	printf("str1:%.8x\n", src);
	printf("str1:%s\n", dst);
	printf("str1:%s\n", src);

}

void lazy() {

	printf("lazy: %s\n", str1);

}

void read_file(int magicword) {

	char buffer1[60];

	printf("read_file\n");
	printf("flag:%d\n", flag);
	printf("magicword:%x\n", magicword);
	
	if(flag && magicword == 0xfefefefe) {
		printf("Second exploits round\n");
		gets(buffer1); //per stampare "Congratulations you win" viene sfruttato questo seconda gets e fare l'overflow su questo buffer interno per chiamare da qui la funzione join_string con strcat dentro e mettendo str2 in str1 e poi chiamare lazy che chiama str1 appena formata
	}
	else 
		printf("Nothing to read!!!");

	printf("str1:%s\n", str1);
	printf("str2:%s\n", str2);
	printf("str1:%x\n", &str1);
	printf("str2:%x\n", &str2);

}

void echo() {

	char* p = NULL;
	char buffer[60];
	char buffer1[60];
	int i;

	printf("Echo\n");
	printf("buffer:%p\n", buffer);
	printf("buffer1:%p\n", buffer1);
	printf("Enter some text:\n");

	//il primo overflow e` sempre qui, sia nell'exploit dello shellcode sia in questo della stampa: 
	gets(buffer1); //prende in input buffer1
	strcpy(p, buffer); //qui si mette buffer in p --> bisogna riempire buffer1 talmente che la parte che finisce su buffer e si mette su p e` cio` che vogliamo (in particolare si modifica p per puntare a una variabile in cui si mette lo shellcode)

	//qui pero` vengono azzerati i buffer
	for(i=0; i<=60; i++) {
		buffer[i] = 0;
		buffer1[i] = 0;
	}	

}

int main() {

	str1[0] = 0;

	echo();

	return 0;

}
