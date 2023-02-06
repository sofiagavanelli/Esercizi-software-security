#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//ci sono diversi punti di exploitation

int security_check = 0 ;

int disable_security_check() { //-> devo riuscire a chiamare questa!! per rendere false il controllo su sec_check
security_check = 0 ;
}
int enable_security_check() {return 1;}


void win(){
	printf("Congratulation, you win!!!!\n") ;
}

void print_function(char *src){

	int canary;
        char dst[100] ;
	int x = rand() ; //num decimale random

	canary = x;
	printf("dst is at %08x, now checking security\n", &dst);
	printf("canary value is: %x\n", canary);

	//mi sa che c'e` un problema con gli indirizzi di x e canary
	printf("canary is: %x\n", &canary);
	printf("x is: %x\n", &x);

        if (security_check)
	{
               strncpy(dst, src, 99); //copia di 99 byte deformata, no prob di buffer overflow
	       dst[100] ='\0' ; //perche il 100esimo lo blocco
	       printf("%s\n", dst) ;	
	}

     else //bisogna usare questo else e questa strcpy per fare exploit
	{
                /* Debugging only */ 
                strcpy(dst, src); //quando uso questa strcpy e vado a generare un overflow devo essere sicuro di sovrascrivere canary e x con lo stesso valore, quindi in particolare devo mettere in canary il valore di x (a x non ho accesso perche` e` sopra dst in memoria e non sotto come canary)
		printf("canary is: %x\n", canary);
		if(canary != x) exit (0); //-> qui devo fare in modo che canary sia = x per non far uscire
		else printf("canary is correct\n");
	}

}



int main(int argc, char *argv[]){

 
 int (*fp)() = NULL; //def di un puntatore a funzione --> devo sovrascrivere questo: sostituire la funz
 char str[260] ;
 short check =0; 
 int i ;
 char index = 0;

        security_check = enable_security_check() ; //ritorna 1 quindi mette a 1 sec_check

	for(i = 0; i < 272; i++) { //--> arriva a 272, ma str e` 260: devo andare a sovrascrivere fp e metterci dentro la funzione che voglio io
	  str[i] = getchar();
	  if(str[i] == 10) break;
	}
	str[i] = 0;
	
	if (fp != NULL) { //se riesco nella sostituzione allora riesco ad entrare qui dentro e a mandarlo
		printf("%p\n", fp);
		fp() ;
		printf("Security Check:%d\n", security_check) ;
	}

	/* print function name */
	print_function(str) ;

	printf("Never return from main\n") ;	
	exit(0) ;
}

