/* The goal of the exploitation is to execute the shellcode */
/* Score: 8 points */

#include <stdio.h>
#include <string.h>

void echo()
{
    char buffer[60] ;
    char buffer1[60] ;

    printf("buffer:%p\n", buffer) ;
    printf("buffer1:%p\n", buffer1) ;
    printf("Enter some text:\n");
    gets(buffer1);
    strcpy(buffer, buffer1) ;
    printf("You entered: %s\n", buffer);
}

int main()
{
    echo();

    return 0;
}
