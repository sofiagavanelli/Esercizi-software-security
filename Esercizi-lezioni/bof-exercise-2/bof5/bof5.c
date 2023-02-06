#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void overflow_function (char *str)
{
  char buffer[100];

  printf("buffer @ %p\n", buffer); //stampa l'indirizzo del buffer
  strcpy(buffer, str);  // Function that copies str to buffer -> la mia stringa deve fare l'overflow del buffer (?)
}

int main(int argc, char *argv[])
{
  overflow_function(argv[1]); //qui devo dare in input una stringa da linea di com
  exit(0);
}

//non c'e` da chiamare una funz ma si puo` iniettare uno shellcode 
//funzione strcpy da attaccare - payload: nop_sled+shellcode+padding(come le nope iniziali, ma non strettamente necessario)+buff_addr
//analizzare codice gdb didass con overflow_function

//shellcode normalmente viene dato all'esame

//nota sull'inserimento da linea di comando: quando mando l'eseguibile con un input molto lungo allora si cambia l'indirizzo del buffer
