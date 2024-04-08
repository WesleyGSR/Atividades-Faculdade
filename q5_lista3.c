#include <stdio.h>
#include <string.h>

int main(){

    char cript[30];
    int i;

    printf("Digite a frase que deseja criptografar: ");
    gets(cript);

    printf("Frase digitada: %s\n", cript);

    for(i = 0; cript[i] != '\0' ; i++){
        if(cript[i] == 'A' || cript[i] == 'a' ||
        cript[i] == 'E' || cript[i] == 'e' ||
        cript[i] == 'I' || cript[i] == 'i' ||
        cript[i] == 'O' || cript[i] == 'o' ||
        cript[i] == 'U' || cript[i] == 'u'){
            cript[i] = '*';
        }
    }

    printf("Frase criptografada: %s", cript);

    return 0;
}