#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void win()
{
printf("Congratulations, you win!!! You successfully changed the code flow\n");

}

void overflow_function (char *str)
{
  char buffer[20];

  strcpy(buffer, str);  // Function that copies str to buffer
}

int main()
{
  char big_string[128];
  int i;

  gets(big_string) ;
  big_string[128] = '\0';
  overflow_function(big_string);
  exit(0); //non si puo` usare la gets nel main perche` non c'e` un return perche` per uscire si usa una syscall di uscita -- bisogna usare la strcpy nella funzione sopra
}

//dobbiamo creare un payload di A*buff_len+indirizzo win
