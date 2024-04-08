#include <stdio.h>
#include <string.h>

int main(){

    char frase[140];
    int i; 
    int A=0, E=0, I=0, O=0, U=0;

    printf("Digite a frase que deseja: ");
    gets(frase);

    for(i = 0; frase[i] != '\0' ; i++){

        if(frase[i] == 'A' || frase[i] == 'a'){
            A++;
        }
        else if(frase[i] == 'E' || frase[i] == 'e'){
            E++;
        }
        else if(frase[i] == 'I' || frase[i] == 'i'){
            I++;
        }
        else if(frase[i] == 'O' || frase[i] == 'o'){
            O++;
        }
        else if(frase[i] == 'U' || frase[i] == 'u'){
            U++;
        }
    }

    printf("Aparecem na frase:\n");
    printf("A: %i vezes.\n", A);
    printf("E: %i vezes.\n", E);
    printf("I: %i vezes.\n", I);
    printf("O: %i vezes.\n", O);
    printf("U: %i vezes.", U);
    
    return 0;
}