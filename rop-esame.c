#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

// bisogna stampare Congratulations user (il nostro nome) you win

char str1[] = "Congratulations                        ";
char str2[] = "you win!  ";
//stringa vuota
char str3[] = "                                                        ";


char vuln() {

	char buffer[128];

	printf("vuln inside\n");
	printf("vuln buf:%x\n", buffer);
	//prende in input il buffer
	gets(buffer);

}

//queste sono l'equivalente di food, feeling_sick e lazy quindi bisogna trovare i gadget
void cpy_string(char *dst, char *src) { //due pop, quindi pop_pop_ret

	printf("copy string\n");
	strcpy(dst, src); //qui c'e` la strcpy

}

void join_string(char *dst, char *src) { //pop_pop_ret

	printf("join_string\n");
	strcat(dst, src);

}

//questa e` l'equivalente del lazy che veniva chiamata alla fine
void win() {

	printf("win\n");
	printf("%s\n", str3);

}


int main(int argc, char **argv) {

	//viene chiamata vuln

	if(argc > 3)
		printf("Exit\n");
	else {
		printf("You win this game if you are able to compose the string Congratulations your name win by using rop technique'\n");
		printf("str1:%x\nstr2:%x\nstr3:%x\n", str1, str2, str3);
		printf("argv[1]:%x\n", argv[1]); //qui potremmo inserire il nostro nome
		vuln();
	}

}


