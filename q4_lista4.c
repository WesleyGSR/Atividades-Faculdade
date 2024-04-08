#include <stdio.h>
#define QTD_CIDADES 4

int main()
{
    float cidades[QTD_CIDADES][QTD_CIDADES];
    int i, j;
    int tamCaminho, caminho[] = {0,2,3,1,0}; 
    float dTotal; 

    for(i=0; i<QTD_CIDADES; i++){
        for(j=0; j < QTD_CIDADES; j++){
            printf("Distancia entre a cidade %i para a cidade %i: ",i+1,j+1);
            scanf("%f", &cidades[i][j]);
        }
    }
    
    tamCaminho = sizeof(caminho) / sizeof(caminho[0]);
    for (int i = 0; i < tamCaminho - 1; i++) {
        dTotal += cidades[caminho[i]][caminho[i + 1]];
    }

    printf("A distancia do percorrida foi de: %.2f.", dTotal);

    return 0;
}
