#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


char string[100] ;

char str1[5] ;
char str2[4] ;

void join_string(char *dst, char *src) 
{
	strcat(dst, src) ;
}

void lazy() 
{
		
	execve(string, 0, 0) ;
}

void get_input()
{

  char *buf = NULL ;
  char buffer[128];
  char buffer1[20] ;


  printf("string: %p\n", string) ;
  printf("join_string %p\n", join_string) ;
  printf("lazy %p\n", lazy) ;

  gets(buffer) ;
  printf("buffer:%s\n", buffer) ;

  /* get input */
  if (buf != NULL){
	  strncpy(buf, buffer, 5) ;
	  printf("buf:%s\n", buf) ;
  }

  buf= NULL ;
  gets(buffer1) ;

  /* get input */
  if (buf != NULL){
	  printf("OK1\n");
	  strncpy(buf, buffer1, 2) ;
	  printf("buf:%s\n", buf) ;
  }

}

int main(int argc, char **argv)
{
  

 get_input() ; 
  
  
}
