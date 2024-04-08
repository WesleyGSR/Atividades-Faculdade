#include <stdio.h>

#define QTD_ALUNOS 3

typedef struct aluno{
    char nome[20];
    char sobrenome[20];
    char matricula[10];
    char turma[20];
    char DN[12];    
}Aluno;

int main(){
    Aluno alunos[QTD_ALUNOS];
    int numeroAluno;

    for(int i = 0; i < QTD_ALUNOS; i++){
        printf("\nAluno %i:\n", i + 1);

        printf("Nome: ");
        scanf("%s", &alunos[i].nome);

        printf("Sobrenome: ");
        scanf("%s", &alunos[i].sobrenome);

        printf("Matricula: ");
        scanf("%s", &alunos[i].matricula);

        printf("Turma: ");
        scanf("%s", &alunos[i].turma);

        printf("Data de nascimento(DD/MM/AAAA): ");
        scanf("%s", &alunos[i].DN);
    }

    printf("\nTabela de alunos:\n");
    for(int i = 0; i < QTD_ALUNOS; i++){
        printf("\nAluno %i:\n", i + 1);
        printf("Nome completo: %s %s\n", alunos[i].nome, alunos[i].sobrenome);
        printf("Matricula: %s\n", alunos[i].matricula);
        printf("Turma: %s\n", alunos[i].turma);
        printf("Data de nascimento: %s\n", alunos[i].DN);
    }
    //Edicao
        
        if(editar_aluno == 'NAO' || editar_aluno == 'nao'){
            printf("Nenhum aluno sera editado.");
            return 0;
        }
        else{
            printf("\nDigite o numero do aluno que deseja editar (1 a %i): ", QTD_ALUNOS);
            scanf("%i", &numeroAluno);

            if(numeroAluno < 1 || numeroAluno > QTD_ALUNOS){
                printf("Nenhum aluno com esse indice.\n");
            } 
            else {
                printf("\nEditando aluno %i:\n", numeroAluno);
                printf("Nome: ");
                scanf("%s", alunos[numeroAluno - 1].nome);
                printf("Sobrenome: ");
                scanf("%s", alunos[numeroAluno - 1].sobrenome);
                printf("Matrícula: ");
                scanf("%s", alunos[numeroAluno - 1].matricula);
                printf("Turma: ");
                scanf("%s", alunos[numeroAluno - 1].turma);
                printf("Data de nascimento(DD/MM/AAAA): ");
                scanf("%s", alunos[numeroAluno - 1].DN);

            printf("\nAluno %i atualizado:\n", numeroAluno);
            printf("Nome completo: %s %s\n", alunos[numeroAluno - 1].nome, alunos[numeroAluno - 1].sobrenome);
            printf("Matricula: %s\n", alunos[numeroAluno - 1].matricula);
            printf("Turma: %s\n", alunos[numeroAluno - 1].turma);
            printf("Data de nascimento: %s\n", alunos[numeroAluno - 1].DN);
            }   
        }
    return 0;
}