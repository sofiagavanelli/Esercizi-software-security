#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


char string[300] ;
int flagvalue ;


int vuln()
{
	char buf[200];

	printf("vuln\n") ;
	printf("10: %c , 11: %c , 12: %c\n", string[10], string[11], string[12]);
	
	if((string[10]=='a') && (string[11]=='b') && (string[12]=='c')){

	    printf("Condition matched\n") ;
	    strcpy(buf, string);
		printf("%p\n", flagvalue);
	}
	else{
	
	return 0;
	
	}

}

int flag(){


	if (flagvalue == 0xdeadbeef)
	    
		printf("you Win!!!!\n") ;
	
	
	else 
		printf("you loose\n") ;

}



void get_input()
{

  char *buf = NULL ;
  char buffer[128];
  char buffer1[20] ;
	//printf("buffer %p , buffer1 %p , string %p , flagvalue %p \n", buffer, buffer1, string, flagvalue);
  gets(buffer) ;
	
  /* get input */
  if (buf != NULL){
	  strcpy(buf, buffer) ;
  }
	printf("59: %p\n", buf);
  buf= NULL ;
  gets(buffer1) ;


  /* get input */
  if (buf != NULL){
	  strcpy(buf, buffer1) ;
  }
	printf("68: %p\n", buf);
}

int main(int argc, char **argv)
{
  

 get_input() ; 
  
  
}
