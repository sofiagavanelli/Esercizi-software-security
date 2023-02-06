#include <stdio.h>
#include <string.h>

void echo()
{
    char buffer[50] ;
    char buffer1[100] ;
    
    printf("buffer:%p\n", buffer) ;
    printf("buffer1:%p\n", buffer1) ;
//qui sopra c'e la stampa degli indirizzi del buffer -> serve per fare l'exploitation
    printf("Enter some text:\n");
    gets(buffer1); //metto 58 su buffer1
    strcpy(buffer, buffer1) ; //copia buffer1 su buffer -> quindi metto 58 su 50: overflow 

//le vulnerabilita potrebbero essere sulla gets o sulla strcpy
//se uno va a sfruttare gets su buffer1 quali potrebbero essere le problematiche ? si puo oltrepassare il buffer fino ad arrivare fino al ret addr ma dopo c'e una strcpy che mette tutto il buffer1 su buffer allora i calcoli fatti per usare la gets non funzionano piu
//bisognerebbe lavorare non piu su buffer1 ma su buffer perche poi verranno spostati su buffer e basteranno per fare overflow

    printf("You entered: %s\n", buffer);
}

int main()
{
    echo();

    return 0;
}

//bisogna costruire l'injection vector -> gdb main, poi:
//pattern create 70 "file1" --lavoriamo su standard input -- diamo in input il file r < file1
//abbiamo ottenuto SIGSEGV quindi per capire precisamente dov'e il ret facciamo pattern search: 
//Registers contain pattern buffer: [...] EIP+0 found at offset: 58 -> che vuol dire che bisogna fornire 58 caratteri
//bisogna fare l'exploit con python

