#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char string[200];
int flagvalue;

int vuln() {

	char buf[160];

	printf("vuln\n");

	if(string[10]=='a'){

		printf("Condition matched\n");
		strcpy(buf, string);

	}
	else {
		return 0;
	}

}

int flag(){

	if(flagvalue == 0xdeadfeef)
		printf("you Win!!!!\n");

	else
		printf("you loose\n");

}


void get_input() {

	//bisogna fare in modo che questo puntatore non sia null
	char *buf = NULL;

	char buffer[128];
	char buffer1[20];

	//partendo dal basso per modificare buf bisogna fare overflow su buffer1 (20) e poi esaurire anche buffer (128) quindi in totale minimo 148 caratteri

	gets(buffer); //si inserisce qualcosa per andare oltre nel caso della shell, nel caso della stampa si usa

	if(buf != NULL){
		strcpy(buf, buffer);
	}

	buf = NULL;
	gets(buffer1); //tramite l'inserimento in buffer1 bisogna arrivare a buf, quindi vanno inseriti min 148 caratteri in questa gets

	if(buf != NULL)
		strcpy(buf, buffer1);

}

int main(int argc, char **argv) {

	get_input();


}
