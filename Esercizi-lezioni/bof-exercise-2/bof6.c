#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void win()
{
  printf("Congratulations, you win!!! You successfully changed the code flow\n");
}

int main(int argc, char **argv)
{
  int (*fp)();
  char buffer[128];

  fp = 0;

  printf("***** BEFORE ATTACK *****\n");
  printf("Variable fp     : %p %p\n", &fp, fp);
  printf("Variable buffer : %p %s\n", &buffer, buffer);
  printf("Function win    : %p\n\n", &win);

  printf("You win this game if you are able to call the function win without change the return address of the main'\n");

  gets(buffer); //il buffer si trova sotto l'fp!! guardare l'ordine di dichiarazione delle variabili perche` creano il layout dello stack
  printf(buffer);

  printf("***** AFTER ATTACK *****\n");
  printf("Variable fp     : %p %p\n", &fp, fp);
  printf("Variable buffer : %p %s\n", &buffer, buffer);

  if(fp) {
      printf("calling function pointer, jumping to %p\n", fp);
      fp(); //istruzione che esegue cio che c'e` in fp -> e` un puntatore a funzione: function pointer: bisogna sovrascrivere fp con l'indirizzo di win
  }
}
