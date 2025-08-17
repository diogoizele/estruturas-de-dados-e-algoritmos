#include <stdio.h>
#include <stdlib.h>

#define ARRAY_INITIAL_LENGTH 5

void array_init(int **arr, int size) {
  for (int i = 0; i < size; i++) (*arr)[i] = 0;
}

void arr_print(int *arr, int length) {
  printf("\n[ ");
  for (int i = 0; i < length; i++) {
    printf("%d", arr[i]);

    if (i != length - 1) printf(", ");
  }
  printf(" ]");
}

int arr_search(int *arr, int length, int item) {
  int i, index = -1;

  for (i = 0; i < length; i++)
    if (arr[i] == item) {
      index = i;
      break;
    }

  return index;
}

int arr_push(int **arr, int *p_length, int *p_capacity, int item) {

  /**
   * Se o tamanho for maior ou igual (>=) à capacidade, exemplo:
   *
   * O tamanho do array será 0 no início e será incrementado a medida
   * que é adicionado elementos.
   *
   * A capacidade começa com o tamanho inicial do array, e vai decrementando
   * a medida que é adicionado elementos.
   *
   * Depois da capacidade inicial ser preenchida, a capacidade sempre será
   * menor que o tamanho do array;
   *
   * imagine um array com tamanho inicial de 5, ao adicionarmos 6x elementos
   * dentro dele, o tamanho será 6 e a capacidade 0, logo, entra no if...
   */
  if (*p_length >= *p_capacity) {
    int *new_arr = (int *)malloc(sizeof(int) * (*p_length + 1));

    if (new_arr == NULL) {
      printf("\nMemory allocation failure");
      return -1;
    }

    for (int i = 0; i < *p_length; i++) new_arr[i] = (*arr)[i];

    free(*arr);

    *arr = new_arr;
  }
  (*arr)[*p_length] = item;

  (*p_length)++;

  if (*p_capacity - 1 >= 0) (*p_capacity)--;

  return *p_length;
}

int arr_unshift(int **arr, int *p_length, int *p_capacity, int item) {
  int i;

  if (*p_length >= *p_capacity) {
    int *new_array = (int *)malloc(sizeof(int) * (*p_length + 1));

    if (new_array == NULL) {
      printf("\nMemory allocation failure");
      return -1;
    }

    for (i = *p_length; i >= 0; i--) new_array[i + 1] = (*arr)[i];

    free(*arr);

    *arr = new_array;
  }

  (*arr)[0] = item;

  (*p_length)++;
  if (*p_capacity - 1 >= 0) (*p_capacity)--;

  return *p_length;
}

int arr_add_at(int **arr, int *p_length, int *p_capacity, int item, int index) {
  int i;

  if (index < 0 || index > *p_length + 1) return -1;

  if (*p_length >= *p_capacity) {
    int *new_arr = (int *)malloc(sizeof(int) * (*p_length + 1));
    array_init(&new_arr, *p_length + 1);

    if (new_arr == NULL) {
      printf("\nMemory allocation failure");
      return -1;
    }

    for (i = 0; i < *p_length; i++) new_arr[i] = (*arr)[i];

    free(*arr);
    *arr = new_arr;
  }

  for (i = *p_length + 1; i >= index; i--) (*arr)[i] = (*arr)[i - 1];

  (*arr)[index] = item;

  (*p_length)++;

  return *p_length;
}

void bubble_sort(int **arr, int length) {
  for (int i = 0; i < length; i++)
    for (int j = 0; j < (length - i - 1); j++)
      if ((*arr)[j + 1] < (*arr)[j]) {
        int temp = (*arr)[j];
        (*arr)[j] = (*arr)[j + 1];
        (*arr)[j + 1] = temp;
      }
}

void reverse(int **arr, int length) {
  int repeat = length / 2;

  if (repeat % 2 != 0) repeat++;

  for (int i = 0; i < repeat; i++) {
    int temp = (*arr)[i];

    (*arr)[i] = (*arr)[length - 1 - i];
    (*arr)[length - 1 - i] = temp;
  }
}

int arr_remove(int **arr, int *p_length, int index) {
  int *new_arr = (int *)malloc(sizeof(int) * (*p_length) - 1);
  int i;

  if (new_arr == NULL) {
    printf("\nMemory allocation failure");
    return -1;
  }

  for (i = 0; i < index; i++) new_arr[i] = (*arr)[i];

  for (i = *p_length; i > index; i--) new_arr[i - 1] = (*arr)[i];

  (*arr) = new_arr;

  (*p_length)--;

  return *p_length;
}

int arr_pop(int **arr, int *p_length) {
  int i, last;
  int *new_arr = (int *)malloc(sizeof(int) * (*p_length) - 1);

  if (new_arr == NULL) {
    printf("\nMemory allocation failed\n");
    return -1;
  }

  for (i = 0; i < *p_length - 1; i++) new_arr[i] = (*arr)[i];

  last = (*arr)[i];

  (*arr) = new_arr;

  (*p_length)--;

  return last;
}

int main() {
  int size = 0;
  int capacity = ARRAY_INITIAL_LENGTH;

  int *arr = (int *)malloc(sizeof(int) * ARRAY_INITIAL_LENGTH);

  array_init(&arr, ARRAY_INITIAL_LENGTH);

  arr_print(arr, ARRAY_INITIAL_LENGTH);

  printf("\nelement %d found on %d index", 5,
         arr_search(arr, ARRAY_INITIAL_LENGTH, 5));
  printf("\nelement %d found on %d index", 70,
         arr_search(arr, ARRAY_INITIAL_LENGTH, 70));

  arr_push(&arr, &size, &capacity, 39);
  arr_push(&arr, &size, &capacity, 45);
  arr_push(&arr, &size, &capacity, 18);
  arr_push(&arr, &size, &capacity, 70);

  arr_print(arr, size);

  arr_push(&arr, &size, &capacity, 20);
  arr_push(&arr, &size, &capacity, 15);
  arr_push(&arr, &size, &capacity, 16);
  arr_push(&arr, &size, &capacity, 200);

  arr_print(arr, size);

  arr_unshift(&arr, &size, &capacity, 17);
  arr_unshift(&arr, &size, &capacity, 28);

  arr_print(arr, size);

  arr_add_at(&arr, &size, &capacity, 4, 6);

  arr_print(arr, size);

  printf("\nelement %d found on %d index", 4, arr_search(arr, size, 4));

  bubble_sort(&arr, size);
  arr_print(arr, size);

  reverse(&arr, size);
  arr_print(arr, size);

  arr_remove(&arr, &size, 9);
  arr_print(arr, size);

  int last_item_removed = arr_pop(&arr, &size);
  printf("\nlast element removed with arr_pop: %d", last_item_removed);

  arr_print(arr, size);

  return 0;
}