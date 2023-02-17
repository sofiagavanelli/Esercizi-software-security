#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int debugging_disable = 1 ;

void print_function(char *src){

	int i = 0;
	char buf[4];
        char dst[100] ;

	printf("dst is at %08x, now checking security\n", &dst);

        if (debugging_disable)
	{
               strncpy(dst, src, 99);
	       dst[100] ='\0' ;
	}

     	else
	{
                /* Debugging only */
                strcpy(dst, src);
	}

}



int main(int argc, char *argv[]){
 
 int c = 0;
 int *fp = &c;
 char str[260] ;
 short check =0; 
 int i ;
 char index = 0;

 	
 	printf("Debugging Disable:%p\n", &debugging_disable) ;

	printf("fp:%p\n", &fp) ;
	for(i = 0; i < 272; i++) {
	  str[i] = getchar();
	  if(str[i] == 10) break;
	}
	str[i] = 0;

	printf("fp:0x%.8x\n", fp) ;
	
	/* print function name */
	*fp = atoi(argv[1]) ;
	print_function(str) ;

	exit(0) ;
 	printf("Never return from main\n") ;	
}
