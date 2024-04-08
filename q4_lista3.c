#include <stdio.h>
#include <string.h>

int main(){

    char nome[50];
    int i, sobrenomes = 0;

    printf("Digite seu nome: ");
    gets(nome);

    for(i=0; nome[i] != '\0'; i++){
        if(nome[i] == ' '){
            sobrenomes++;
        }
    }
    sobrenomes = sobrenomes - 1;
    if(sobrenomes < 2){
        sobrenomes = 2;
    }
    
    printf("A pessoa chamada %s tem %i sobrenomes.",nome, sobrenomes);

    return 0;
}