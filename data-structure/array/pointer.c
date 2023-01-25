#include <stdio.h>

int main() {

  int a = 5;
  int *b;  // <- pointer to int

  b = &a;

  printf("value of a = %d\n", a);
  printf("value of a = %d\n", *(&a));
  printf("value of a = %d\n", *b);
  printf("address from a = %p\n", &a);
  printf("address from a = %p\n", b);
  printf("address from b = %p\n", &b);
  printf("value of b = address from a = %p\n", b);

  return 0;
}