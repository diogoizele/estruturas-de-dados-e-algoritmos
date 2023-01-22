#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 2

void push_back(int **arr, int elem, int *p_size, int *p_capacity)
{
    // Se o tamanho do array é igual ou maior que a capacidade, precisamos alocar mais memória
    if (*p_size >= *p_capacity)
    {
        // Aumentamos a capacidade do array
        *p_capacity = *p_size + 2;
        // Alocamos memória para o novo array
        int *new_arr = (int *)realloc(*arr, sizeof(int) * (*p_capacity));
        // Verifica se a memória foi alocada corretamente
        if (new_arr == NULL)
        {
            printf("Erro ao alocar memória!\n");
            return;
        }

        free(arr);

        *arr = new_arr;
    }
    // Adicionamos o elemento no final do array
    (*arr)[*p_size] = elem;
    (*p_size)++;
}

int main(void)
{

    int *arr = (int *)malloc(sizeof(int) * INITIAL_SIZE);
    int arr_size = 0, arr_capacity = 2;

    push_back(&arr, 10, &arr_size, &arr_capacity);
    push_back(&arr, 11, &arr_size, &arr_capacity);
    printf("\nArr: \n");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    push_back(&arr, 12, &arr_size, &arr_capacity);
    push_back(&arr, 13, &arr_size, &arr_capacity);
    push_back(&arr, 14, &arr_size, &arr_capacity);
    printf("\nArr: \n");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    return 0;
}