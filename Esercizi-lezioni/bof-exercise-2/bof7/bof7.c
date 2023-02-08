#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int security_check = 0 ;

int disable_security_check() {
security_check = 0 ;
}
int enable_security_check() {return 1;}


void win(){
	printf("Congratulation, you win!!!!\n") ;
}

void print_function(char *src){

        char dst[230] ;

	printf("dst is at %08x, now checking security\n", &dst);

        if (security_check)
	{
               strncpy(dst, src, 229);
	       dst[230] ='\0' ;
	       printf("%s\n", dst) ;	
	}

     else
	{
                /* Debugging only */
                strcpy(dst, src);
	}

}

//scopo: chiamare win()

int main(int argc, char *argv[]){

 
 int (*fp)() = NULL; //def di un puntatore a funzione
 char str[260] ;

 short check =0; 
 int i ;
 char index = 0;

        security_check = enable_security_check() ; //ritorna 1 quindi mette a 1 sec_check (var globale)

	for(i = 0; i < 268; i++) { 
	  str[i] = getchar();
	  if(str[i] == 10) break;
	}
	str[i] = 0;
	
	if (fp != win && fp != NULL) fp() ; //qui viene invocata la funzione contenuta in fp (function pointer): il nostro scopo e` riuscire a inserire a chiamare win ma non posso inserire in fp l'indirizzo di win perche` non entrerebbe nell'if!!! allora come? devo entrare in print_function ed entrare nell'else per sfruttare la strcpy e fare overflow MA quindi prima devo riuscire a disabilitare il security check
	printf("Security Check:%d\n", security_check) ;

	/* print function name */
	print_function(str) ;

	exit(0) ;
 	printf("Never return from main\n") ;	
}









