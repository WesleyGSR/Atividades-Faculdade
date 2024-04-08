#include <stdio.h>

#define QTD_ALUNOS 10

typedef struct aluno{
    char nome[20];
    char sobrenome[20];
    int matricula;
    char turma[20];
    char DN[10];    
}Aluno;

int main(){
    Aluno alunos[QTD_ALUNOS];

    for(int i = 0; i < QTD_ALUNOS; i++){
        printf("\nAluno %i:\n", i + 1);

        printf("Nome: ");
        scanf("%c", alunos[i].nome);

        printf("Sobrenome: ");
        scanf("%c", alunos[i].sobrenome);

        printf("Matricula: ");
        scanf("%i", alunos[i].matricula);

        printf("Turma: ");
        scanf("%c", alunos[i].turma);

        printf("Data de nascimento (DD/MM/AAAA): ");
        scanf("%c", alunos[i].DN);
    }

    printf("Tabela de alunos:\n");
    for(int i = 0; i < QTD_ALUNOS; i++){
        printf("\nAluno %i:\n", i + 1);
        printf("Nome completo: %s %s\n", alunos[i].nome, alunos[i].sobrenome);
        printf("Matricula: %i\n", alunos[i].matricula);
        printf("Turma: %s\n", alunos[i].turma);
        printf("Data de nascimento: %s\n", alunos[i].DN);
    }

    return 0;
}