#include <stdio.h>

int main(){

    char Gabarito[20];
    char Respostas[20];
    int i, alunos, acertos=0;
    float nota;

    //Gabarito
    for(i=0; i<=19; i++){
        printf("Diga a resposta da questao %i (A,B,C,D ou E): ", i+1);
        scanf("%c", &Gabarito[i]);
    }
    
    //Respostas dos Alunos
    for(alunos = 0; alunos <= 50; alunos++){
        for(i = 0; i <= 19; i++){
            printf("Diga a resposta da questao %i do aluno %i (A, B, C, D ou E): ", i+1, alunos + 1);
            scanf("%c", &Respostas[i]);
        }
        
        for(i = 0; i <= 19; i++){
            if(Gabarito[i] == Respostas[i]){
                acertos++;
             
            }
        }
   
        nota = (float)acertos / 2;
        printf("Aluno %i: %i acertos e nota %.2f\n", alunos+1, acertos, nota);
        if(nota >= 6){
        printf("APROVADO\n");
        } 
        else{
            printf("REPROVADO\n");
        }
        //Zerando os acertos para poder reutilizar a variavel
        acertos = 0;
    }

    return 0;

}