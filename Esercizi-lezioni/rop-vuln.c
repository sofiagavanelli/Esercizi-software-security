#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char string[100];

void lazy() {
  system(string);
}

void food(int magic) {
  if (magic == 0xdeadbeef) { //qui 1 pop ret
    strcat(string, "/bin");
  }
}

void feeling_sick(int magic1, int magic2, char *filename) {
  if (magic1 == 0xd15ea5e && magic2 == 0x0badf00d) { //qui pop pop pop ret perche` ci sono 3 parametri
    strcat(string, "/cat "); 
    strcat(string, filename);
  }
}

void vuln(char *string) { //un pop ret

  //secondo spiazzamento
  char buffer[100] = {0};
  strcpy(buffer, string); //arg1 che viene messo dentro il buffer
}

int main(int argc, char** argv) { //arg 1 > 100 e arg 2 > 50
  string[0] = 0;

  //primo spezzamento da buf a filename
  char filename[]="filename";
  char buf[50] ;

  printf("me Can I read the secret file?! \n\n");
  if (argc > 2) { //bisogna dare 2 argomenti

    //primo overflow su buf: ci permette di andare a sovrascrivere il filename con secret-file
    strcpy(buf, argv[2]) ; //secondo argomento in buffer --> qui per fare overflow mi servono piu` di 50 caratteri

    //per scoprire dov'e` filename
    printf("%p:%s\n", filename, filename);
    
    //il secondo e` su argv1
    vuln(argv[1]); //primo argomento viene dato a vuln, funzione VULNerabile <-- qui mi servono piu` di 100 caratteri

  } else {
    printf("You forgot to read me!!!\n");
  }
  return 0;
}



