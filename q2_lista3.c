#include <stdio.h>

int main(){

    int gabarito[10], respostas[10];
    int apostadores, cartao, acertos = 0;
    int i, apostador;

    for(i = 0; i <= 9; i++){
        printf("Gabarito - %i numero: ", i+1);
        scanf("%i", &gabarito[i]);
    }
    
    printf("Diga a quantidade de apostadores no jogo: ");
    scanf("%i", &apostadores);

    for(apostador = 0; apostador <= apostadores; apostador++){ 
        printf("Digite o numero do cartao do apostador %i: ", apostador + 1);
        scanf("%i", &cartao);

        for (int i = 0; i < 10; i++) {
            printf("Digite o numero %i do apostador %i: ",i + 1, apostador + 1);
            scanf("%i", &respostas[i]);
        }

        for(i = 0; i <=9; i++){
            if(respostas[i] == gabarito[i]){
                acertos = acertos + 1;
            }
        }

        printf("Apostador %i teve %i acertos.\n", apostador + 1, acertos);
        if (acertos == 10) {
            printf("Apostador %i e o GANHADOR! Seu cartao era: %i\n", apostador + 1, cartao);
        }
        else{
            acertos = 0;
        }
    }

    return 0;
}