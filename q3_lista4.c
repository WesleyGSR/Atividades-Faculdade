#include <stdio.h>
#define ALUNOS 3
#define NOTAS 4

int main()
{
    float notas[ALUNOS][NOTAS];
    float media1[ALUNOS], media2[ALUNOS], mediaF[ALUNOS];
    int i,j;
    
    for(i=1; i <= ALUNOS; i++){
        for(j=1; j <= NOTAS; j++){
            printf("Aluno %i nota %i: ",i,j);
            scanf("%f",&notas[i][j]);
        }
    }
    
    for(i=0; i < ALUNOS; i++){
        media1[i] = (notas[i][1] + notas[i][2]) / 2;
        media2[i] = (notas[i][2] + notas[i][3]) / 2;
        mediaF[i] = (media1[i] * 2 + media2[i] * 3) / 5;
        
    }
    printf("%f",mediaF);
    
   
    return 0;
}
