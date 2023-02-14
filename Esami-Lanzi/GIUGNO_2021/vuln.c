#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


char string[200] ;
int flagvalue ;


int vuln()
{
	char buf[160];

	printf("vuln\n") ;
	
	if(string[10]=='a'){

	    printf("Condition matched\n") ;
	    strcpy(buf, string);

	}
	else{
	
	return 0;
	
	}

}

int flag(){


	if (flagvalue == 0xdeadfeef)
	    
		printf("you Win!!!!") ;
	
	
	else 
		printf("you loose\n") ;

}



void get_input()
{

  char *buf = NULL ;
  char buffer[128];
  char buffer1[20] ;

  gets(buffer) ;

  /* get input */
  if (buf != NULL){
	  strcpy(buf, buffer) ;
  }

  buf= NULL ;
  gets(buffer1) ;


  /* get input */
  if (buf != NULL){
	  strcpy(buf, buffer1) ;
  }

}

int main(int argc, char **argv)
{
  

 get_input() ; 
  
  
}
