#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char string[100];

//num 3
void lazy() {
  system(string);  //<-- chiama cio` che c'e` in stringa
}

//num 1
void food(int magic) {
  printf("THANK YOU!\n");
  if (magic == 0xdeadbeef) {
    strcat(string, "/bin"); //aggiungo /bin all'invocazione
  }
}

//num 2
void feeling_sick(int magic1, int magic2) { 
  printf("I'm Feeling sicK...\n");
  if (magic1 == 0xd15ea5e && magic2 == 0x0badf00d) {
    strcat(string, "/echo 'This message will self destruct in 30 seconds...BOOM!'"); //<--concludo la stringa in pasto a system in lazy
  }
}

void vuln(char *string) {
  char buffer[100] = {0};
  strcpy(buffer, string); // I don't know any better.
}

int main(int argc, char** argv) {
  string[0] = 0;

  printf("me Hungry...Can I have Shell?! Feed me some beef \n\n");
  if (argc > 1) {
    vuln(argv[1]);
  } else {
    printf("You forgot to feed me!!!\n");
  }
  return 0;
}
