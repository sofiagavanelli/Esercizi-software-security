#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int debugging_disable = 1 ;
int magic_word = 0x0 ;
char string[100] ;

void lazy(){

printf("we're in lazy");
system(string) ;

}

void food(int magic)
{
	if(magic==0xdeadbeef && magic_word == 0x00004589)
	{

		strcpy(string, "/bin") ;
                printf("we're in food");
	}

}

void feeling_sick(int magic1, int magic2)
{
	if(magic1 == 0xd15ea5e && magic2 == 0x0badf00d && magic_word == 0x00004589){
                printf("we're in feeling sick");
		strcat(string, "/sh") ;

	}

}

void print_function(char *src){

        char dst[240] ;

	printf("dst is at %x\n, now checking security\n", &dst);
        printf("debug_dis_add %x\n", &debugging_disable);
	printf("debug_dis_val %x\n", debugging_disable);
        printf("magic_word %x\n", &magic_word);
        printf("magic_word val %x\n", magic_word);
        printf("magic_word == 0x00004589: %x\n", magic_word == 0x00004589);

        if (debugging_disable)
	{
               strncpy(dst, src, 239);
	       dst[240] ='\0' ;
	}

     	else
	{
                /* Debugging only */
                printf("ENTERED\n");
                strcpy(dst, src);
	}

}



int main(int argc, char *argv[]){
 
 int c = 0;
 int *mw = 0xbffe4589;
 int *fp = &c;
 char str[260] ;
 short check = 0; 
 int i ;
 char index = 0;

	printf("fp:%p\n", fp) ;
        printf("fp value: %d\n", *fp);
        printf("debug_dis_add %x\n", &debugging_disable);
        printf("debug_dis_val %x\n", debugging_disable);
        printf("magic_word %x\n", &magic_word);
        printf("magic_word val %d\n", magic_word);
        printf("str add %x\n", &str);
        printf("mw: %x\n", mw);
        printf("mw: %x\n", *mw);
        printf("food: %x\n", food);
        printf("sick: %x\n", feeling_sick);
        printf("lazy: %x\n", lazy);
        // unsigned long value = strtoul("0xbffe4589", NULL, 16);
        // printf("magic in int : %lu\n", value);
	for(i = 0; i < 278; i++) {
	  str[i] = getchar();
	  if(str[i] == 10) break;
	}
	str[i] = 0;
        printf("fp value: %d\n", *fp);
        printf("fp : %p\n", fp);
        printf("debug_dis_add %x\n", &debugging_disable);
	printf("debug_dis_val %x\n", debugging_disable);
        printf("magic_word %x\n", &magic_word);
        printf("magic_word val %x\n", magic_word);
        printf("mw: %x\n", mw);
        printf("mw: %x\n", *mw);
	/* print function name */
	*fp = atoi(argv[1]) ;
	*mw = atoi(argv[2]) ;
	print_function(str) ;

	exit(0) ;
 	printf("Never return from main\n") ;	
}
