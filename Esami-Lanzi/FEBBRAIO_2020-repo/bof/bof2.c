/* DEP protection */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char str[]="/bin/sh";
char chr[]="\0";

int bof(char *str)
{
	char buffer[10];

	printf("buffer:%x\n", buffer) ;
	strcpy(buffer, str);
	return 1;
}

int main(int argc, char **argv)
{
	char str[517];
	FILE *badfile;
	badfile = fopen("badfile", "r");
	fread(str, sizeof(char), 517, badfile);
	bof(str);
	printf("Returned Properly\n");
	return 1;
}

