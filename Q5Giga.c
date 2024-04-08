#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QTD 3
#define SAIR 7
typedef struct conta{
    int numero;
    char cliente[100];
    float saldo;
} Conta;

int menu(){
    int opcao;
    printf("Menu de opcoes:\n" 
    "1. Cadastrar\n"   
    "2. Visualizar a conta de um determinado cliente pelo numero\n"
    "3. Depositar na conta\n"
    "4. Excluir a conta com o menor saldo\n"
    "5. Mostrar todas as contas\n"
    "6. Editar dados\n"
    "7. Sair\n" 
    "Opcao: ");
    scanf("%i", &opcao);
    return opcao;
}

int main()
{
    Conta banco[QTD], temp;
    // Variavel para armazenar a opção do menu
    int opcao;
    // Variavel que armazena a posição no vetor banco
    int index=0; 
    // Variável para executar o for
    int j;
    // Variável flag para verificar conta com mesmo numero
    int repetir=0;
    // Variavel para armazenar se o usuario deseja salvar
    int salvar;
    int pesquisa;
    int encontrado=0, iencontrado;
    int imenor;
    float deposito, menor;
    do{
        opcao = menu();
        switch(opcao){
            case 1:
                if(index<QTD){
                    do{
                        // Zerar a flag de repetição
                        repetir=0;
                        // Solicitar o numero da conta e salvar na variavel temporaria
                        printf("Conta %i\n", index+1);
                        printf("Digite o número da conta: ");
                        scanf("%i", &temp.numero);
                        getchar();
                        // Verificar se o numero ja foi cadastrado
                        for(j=0; j<index; j++){
                            if(temp.numero == banco[j].numero){
                                printf("Numero ja existente! digite novamente!\n");
                                // Setar flag para solicitar o numero da conta
                                repetir=1;
                            }
                        }
                    }while(repetir==1);
                    // Digitar o nome do cliente
                    printf("Digite o nome do cliente: ");
                    gets(temp.cliente);
                    // Iniciar saldo zerado
                    temp.saldo = 0;
                    
                    printf("Deseja salvar? (1-Sim,2-Nao) ");
                    scanf("%i", &salvar);
                    if(salvar==1){
                        // Armazenar a conta temporária no vetor de contas banco
                        banco[index] = temp;
                        // Incrementar a posição para a proxima conta
                        index++;
                        printf("Cadastro realizado com sucesso!\n");
                    }
                    else{
                        printf("Cadastrado cancelado!\n");
                    }
                }
                else{
                    printf("Numero maximo de cadastro excedido!\n");
                }
                break;
            case 2:
                printf("Digite o numero da conta desejada:");
                scanf("%i", &pesquisa);
                encontrado = 0;
                
                for(j=0; j<index; j++){
                    if(pesquisa == banco[j].numero){
                        printf("Cliente: %s\n", banco[j].cliente);
                        printf("Saldo: R$%.2f\n", banco[j].saldo);
                        encontrado=1;
                    }
                }
                if(encontrado=0){
                    printf("Cliente inexistente!\n");
                }
                break;
            case 3:
                printf("Digite o numero da conta desejada:");
                scanf("%i", &pesquisa);
                printf("Digite o valor a depositar:");
                scanf("%f", &deposito);
                encontrado = 0;
                
                for(j=0; j<index; j++){
                    if(pesquisa == banco[j].numero){
                        banco[j].saldo = deposito;
                        encontrado=1;
                    }
                }
                if(encontrado=0){
                    printf("Cliente inexistente!\n");
                }
                else{
                    printf("Deposito realizado com sucesso!\n");
                }
                break;
            case 4:
                // Procurando conta com menor saldo
                menor = banco[0].saldo;
                imenor = 0;
                
                for(j=1; j<index; j++){
                    if(banco[j].saldo < menor){
                        menor = banco[j].saldo;
                        imenor = j;
                    }
                }
                // Apagar conta com menor saldo
                for(j=imenor; j<index-1; j++){
                    banco[j] = banco[j+1];
                }
                index--;
                
                printf("Conta excluida com sucesso!\n");
                
                break;
            case 5:
                printf("Contas cadastradas\n");
                for(j=0; j<index; j++){
                    printf("Numero: %i Cliente: %s Saldo: R$%.2f\n",
                    banco[j].numero, banco[j].cliente, banco[j].saldo);
                }
                break;
            case 6:
                printf("Digite o numero da conta desejada:");
                scanf("%i", &pesquisa);
                getchar();
                encontrado = 0;
                
                for(j=0; j<index; j++){
                    if(pesquisa == banco[j].numero){
                        printf("Cliente: %s\n", banco[j].cliente);
                        printf("Saldo: R$%.2f\n", banco[j].saldo);
                        encontrado = 1;
                        iencontrado = j;
                    }
                }
                if(encontrado == 1){
                    temp.numero = banco[iencontrado].numero;
                    temp.saldo = banco[iencontrado].saldo;
                    
                    printf("Digite o nome atualizado do cliente: ");
                    gets(temp.cliente);
                    
                    printf("Deseja salvar? (1-Sim,2-Nao) ");
                    scanf("%i", &salvar);
                    if(salvar==1){
                        // Armazenar a conta temporária no vetor de contas banco
                        banco[iencontrado] = temp;
                        // Incrementar a posição para a proxima conta
                        printf("Atualizacao realizada com sucesso!\n");
                    }
                    else{
                        printf("Atualizacao cancelada!\n");
                    }
                }
                else{
                    printf("Conta nao cadastrada!\n");
                }
                break;
            case SAIR:
                printf("Programa encerrado!\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }while(opcao!=SAIR);

    return 0;
}