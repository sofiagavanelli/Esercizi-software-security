#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void free_memory(char *secret){ free(secret) ; }


get_input(char *str){

	char p[20] ;

	gets(str) ;
	strcpy(p, str) ;
	printf("%s\n", p) ;

}

void build_secret(char *k)
{
  int i;
  for (i=0; i<7; i++)
    k[i] = rand() %100+1;
  k[7] = '\0' ;
}

void check_password(char *secret)
{

	char input[100];
	char *input_secret;
	
	input_secret = malloc(24) ;
	if(!strcmp(input_secret, secret))
	{
		printf("You got high privilege\n") ;
		gets(input) ;

	}
	
}


int main(int argc, char *argv[]){

 char *secret ;
 char input[120] ;

 	printf("Successful exploit use after free vulnerability to get high priviledge and then  execute the /bin/sh shellcode\n") ;
 	secret = malloc(24) ;
	build_secret(secret) ;

	get_input(input) ;
	check_password(secret);
	exit(0) ;

}
