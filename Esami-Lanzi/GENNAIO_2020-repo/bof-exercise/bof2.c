/* The goal of the exercise is to execute the function win 
   Score: 5 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int debugging_disable = 1 ;

void win(){
	printf("Congratulation, you win!!!!\n") ;
}

void print_function(char *src){

        char dst[230] ;

	printf("dst is at %08x, now checking security\n", &dst);

        if (debugging_disable)
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



int main(int argc, char *argv[]){

 
 int c ;
 int *fp = &c;
 char str[260] ;
 short check =0; 
 int i ;
 char index = 0;


	for(i = 0; i < 268; i++) {
	  str[i] = getchar();
	  if(str[i] == 10) break;
	}
	str[i] = 0;
	

	/* print function name */
	*fp = atoi(argv[1]) ;
	print_function(str) ;

	exit(0) ;
 	printf("Never return from main\n") ;	
}
