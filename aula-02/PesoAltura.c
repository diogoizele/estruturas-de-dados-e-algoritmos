#include <stdio.h>
#include <malloc.h>
#define ALTURA_MAXIMA 225;

typedef struct
{
    int peso;   // peso em quilogramas
    int altura; // altura em centimetros
} PesoAltura;

int main()
{

    /*
    // Sem Malloc:
    PesoAltura pessoa1;
    pessoa1.peso = 80;
    pessoa1.altura = 169;
    */

    PesoAltura *pessoa1 = (PesoAltura *)malloc(sizeof(PesoAltura));
    pessoa1->peso = 80;
    pessoa1->altura = 169;

    printf("Peso: %i, ALtura %i ", pessoa1->peso, pessoa1->altura);
    return 0;
}