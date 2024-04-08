#include <stdio.h>
#include <math.h>


typedef struct ponto{
    float x;
    float y;
}Ponto;

int main()
{
    Ponto p1;
    Ponto p2;
    float distancia;
    
    printf("Digite o ponto 1 (x,y): ");
    scanf("%f,%f",&p1.x,&p1.y);
    printf("Digite o ponto 2 (x,y): ");
    scanf("%f,%f",&p2.x,&p2.y);
    
    distancia = sqrt( pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    
    printf("Distancia entre os pontos: %.2f",distancia);
    
    return 0;
}

