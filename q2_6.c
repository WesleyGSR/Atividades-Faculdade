#include <stdio.h>
#include <math.h>

typedef struct retangulo{
    struct pontose{
        float x;
        float y;
    };

    struct pontoid{
        float x;
        float y;
    };

}Retangulo;

int main(){
    struct pontose p1;
    struct pontoid p2;
    float area, diagonal, arestaV, arestaH;
    
    printf("Ponto superior esquerdo(x,y): ");
    scanf("%f,%f", &p1.x, &p1.y);
    printf("Ponto inferior direito(x,y): ");
    scanf("%f,%f", &p2.x, &p2.y);

    area = (p1.x - p2.x) * (p1.y - p2.y);
    diagonal = sqrt( pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    arestaV = p1.y - p2.y;
    if(arestaV < 0){
        arestaV = arestaV - (2*arestaV);
    }
    arestaH = p1.x - p2.x; 
    if(arestaH < 0){
        arestaH = arestaH - (2*arestaH);
    }

    printf("A area vale: %.2f\n", area);
    printf("O comprimento da diagonal vale: %.2f\n", diagonal);
    printf("As arestas verticais tem valor: %.2f\n", arestaV);
    printf("As arestas horizontais tem valor: %.2f", arestaH);

    return 0;
}
