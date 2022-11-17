#include <stdio.h>

#define MAX_LENGTH 15

typedef int KEY;

typedef struct
{
    KEY key;
    int age;
} ITEM;

typedef struct
{
    ITEM itens[MAX_LENGTH];
    int elementsAmount;
} LIST;

void initialize(LIST *list)
{
    list->elementsAmount = 0;
}

int length(LIST *list)
{
    return list->elementsAmount;
}

int add(LIST *list, ITEM item)
{
    if (list->elementsAmount > MAX_LENGTH)
        return -1;
    else
    {
        list->itens[list->elementsAmount] = item;
        list->elementsAmount++;
        return list->elementsAmount;
    }
}

int addAtIndex(LIST *list, ITEM item, int index)
{
    int aux;

    if ((list->elementsAmount == MAX_LENGTH) || (index < 0) || (index > list->elementsAmount))
    {
        if (list->elementsAmount == MAX_LENGTH)
            printf("[erro] a lista já está cheia\n");
        else if (index < 0)
            printf("[erro] índice inválido - a menor posição válida é: 0\n");
        else if (index > list->elementsAmount) // garante que não terão espaços vazios dentro do arranjo - lista linear SEQUENCIAL
            printf("[erro] índice inválido - maior que o número de elementos\n- elementsAmount: %d\n- index: %d\n", list->elementsAmount, index);
        return -1;
    }

    for (aux = list->elementsAmount; aux > index; aux--)
        list->itens[aux] = list->itens[aux - 1];

    list->itens[index] = item;
    list->elementsAmount++;

    return index;
}

void showList(LIST *list)
{
    int i;
    printf("Lista de tamanho: %d\n-----------------\n", list->elementsAmount);
    for (i = 0; i < list->elementsAmount; i++)
        printf("LIST[%d]: {key: %d, age: %d}\n", i, list->itens[i].key, list->itens[i].age);
    printf("-----------------\n");
}

int getIndexByKey(LIST *list, KEY key)
{
    int index = -1;
    while (index < list->elementsAmount)
    {
        if (list->itens[index].key == key)
            return index;

        else
            return -1;
    }

    return index;
}

int main(void)
{

    LIST list;
    printf("Declaração da lista: %d\n", list.elementsAmount); // https://stackoverflow.com/questions/1597405/what-happens-to-a-declared-uninitialized-variable-in-c-does-it-have-a-value

    initialize(&list);
    printf("Inicialização da lista: %d\n", list.elementsAmount);

    showList(&list);

    int listLength = length(&list);
    printf("Tamanho da lista: %d\n", listLength);

    ITEM item1;
    item1.key = 1;
    item1.age = 20;

    ITEM item2;
    item2.key = 2;
    item2.age = 34;

    ITEM item3;
    item3.key = 3;
    item3.age = 15;

    ITEM item4;
    item4.key = 4;
    item4.age = 45;

    int index = add(&list, item1);
    add(&list, item2);
    add(&list, item3);
    printf("Índice novo elemento: %d\n", index);
    printf("Idade do primeiro elemento da lista: %d\n", list.itens[0].age);

    showList(&list);

    printf("Key do segundo elemento: %d\n", list.itens[1].key);
    addAtIndex(&list, item4, 1);
    printf("NOVA Key do segundo elemento: %d\n", list.itens[1].key);
    printf("Key do terceiro elemento: %d\n", list.itens[2].key);

    showList(&list);

    printf("NOVO Tamanho da lista: %d\n", length(&list));
    addAtIndex(&list, item1, 5);

    showList(&list);
}