#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int security_check = 0 ;

int disable_security_check() {
security_check = 0 ;
}
int enable_security_check() {return 1;}


void print_function(char *src){

        int canary;
        char dst[120] ;

	int x = rand() ;

	canary = x ;
	printf("dst is at %08x, now checking security\n", &dst);
	printf("canary value is: %x\n", canary);
	printf("x value is: %x\n", x);

        if (security_check)
	{
               strncpy(dst, src, 119);
	       dst[120] ='\0' ;
	       printf("%s\n", dst) ;	
	}

     else
	{
                strcpy(dst, src);
		printf("canary is: %x\n", canary) ;
		if (canary != x) exit(0) ;
		else printf("Canary is correct\n");
	}

}



int main(int argc, char *argv[]){

 
 int (*fp)() = NULL;
 char str[270] ;
 short check =0; 
 int i ;
 char index = 0;

        security_check = enable_security_check() ; //qui security_check va a 1

	for(i = 0; i < 282; i++) { //il buffer str e` 270 ma qua si prendono 282 -- si passa su fp
	  str[i] = getchar();
	  if(str[i] == 10) break;
	}
	str[i] = 0;
	
	if (fp != NULL){
					printf("%p\n", fp) ; //si stampa il puntatore
	       	fp() ; //si chiama la funzione che c'e` dentro
		printf("Security Check:%d\n", security_check) ; //stampa security
	}

	/* print function name */
	print_function(str) ;

 	printf("Never return from main\n") ;	
	exit(0) ;
}



