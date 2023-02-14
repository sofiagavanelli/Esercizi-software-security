#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

// you need to print Congratulations user you win


char str1[]= "Congratulations                    " ;
char str2[] = "you win!    " ;
char str3[] = "                                                              " ;


void vuln(){

  char buffer[140];
  
  printf("vuln inside\n");
  printf("vuln buf:%x\n", buffer) ;
  gets(buffer);

}

void cpy_string(char *dst, char *src)
{

	printf("copy string\n") ;
	strcpy(dst, src) ;


}

void join_string(char *dst, char *src) 
{
	printf("join_string\n") ;
        strcat(dst, src) ;
}

void win()
{
   printf("win\n") ;
   printf("%s\n", str3);
}

int main(int argc, char **argv)
{

  if(argc < 3)
	  printf("Exit\n") ;
  else
  {

  	printf("You win this game if you are able to compose the string Congratulations your name win by using rop technique'\n");
	printf("str1:%x\nstr2:%x\nstr3%x", str1, str2, str3) ;
	printf("argv[1]:%x\n", argv[1]);
	vuln();	

   }

}
