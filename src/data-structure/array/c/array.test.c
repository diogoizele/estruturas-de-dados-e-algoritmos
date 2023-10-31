#include "array.c"
#include <stdio.h>
#include <stdlib.h>

void pause() {
  printf("Press any key to continue");
  while (getchar() != '\n') {}
  getchar();
}

int main() {

  int option, operation;
  Array *array;

  do {
    system("clear");
    printf("-------------------------------\n");
    printf("*             Array           *\n");
    printf("*                             *\n");
    printf("* 0 - Exit                    *\n");
    printf("* 1 - Create array            *\n");
    printf("-------------------------------\n");
    printf("Enter an option: ");
    fflush(stdin);

    scanf("%d", &option);

    if (option == 1) {
      int size = 0;
      printf("Enter with array length: ");

      scanf("%d", &size);

      array = create(size);

      do {

        int element, index, response;

        system("clear");
        printf("-------------------------------\n");
        printf("*      Array - Operations     *\n");
        printf("*                             *\n");
        printf("* 0 - Exit                    *\n");
        printf("* 1 - Print                   *\n");
        printf("* 2 - Insert                  *\n");
        printf("* 3 - Exclude                 *\n");
        printf("* 4 - Push                    *\n");
        printf("* 5 - Update                  *\n");
        printf("* 6 - Reset                   *\n");
        printf("-------------------------------\n");
        printf("Enter an option: ");

        fflush(stdin);
        scanf("%d", &operation);

        switch (operation) {
          case 0:
            operation = 0;
            break;
          case 1:
            print(array);
            pause();

            break;
          case 2:

            printf("Enter with an element: ");
            scanf("%d", &element);

            printf("Insert this element at which index: ");
            scanf("%d", &index);

            response = insert(array, index, element);
            if (response == SUCCESS) {
              printf("Success to insert!\n");
            } else {
              printf("Failed to insert!\n");
            }

            pause();
            break;
          case 3:

            printf("Enter with index of removed element: ");
            scanf("%d", &index);

            response = exclude(array, index);
            if (response == SUCCESS) {
              printf("Success to exclude!\n");
            } else {
              printf("Failed to exclude!\n");
            }

            pause();

            break;
          case 4:
            printf("Enter with an element: ");
            scanf("%d", &element);

            response = push(array, element);
            if (response == SUCCESS) {
              printf("Success to push!\n");
            } else {
              printf("Failed to push!\n");
            }

            pause();

            break;
          case 5:
            printf("Enter with an new element: ");
            scanf("%d", &element);

            printf("Enter with index by element you want update: ");
            scanf("%d", &index);

            response = update(array, index, element);
            if (response == SUCCESS) {
              printf("Success to update!\n");
            } else {
              printf("Failed to update!\n");
            }

            pause();

            break;
          case 6:

            response = reset(array);
            if (response == SUCCESS) {
              printf("Success to reset array!\n");
            } else {
              printf("Failed to reset!\n");
            }

            pause();

            break;
          default:
            printf("\nUnknown operation %d\n", operation);
            pause();
        }
      } while (operation != 0);
    }

  } while (option != 0);

  return 0;
}
