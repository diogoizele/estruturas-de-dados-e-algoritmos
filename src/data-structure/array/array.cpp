#include <cstdio>
#include <cstdlib>
#include <iostream>

#define MEMORY_CLEANED -1
#define SUCCESS 0
#define INVALID_POSITION 1
#define ARRAY_FULL 2
#define INITIALIZED 3
#define EMPTY 4

using namespace std;

class Array {
 private:
  int size;
  int *elements;

 public:
  Array(int size);
  static Array *copy(Array *other);
  int insert(int index, int element);
  int exclude(int index);
  int push(int element);
  int update(int index, int element);
  int reset();
  void print();
  int length();
};

Array::Array(int size) {
  this->size = size;
  this->elements = new int[size];
};

Array *Array::copy(Array *other) {
  int size = other->size;
  Array *newArray = new Array(size);

  for (int i = 0; i < size; i++) {
    newArray->elements[i] = other->elements[i];
  }

  return newArray;
}

int Array::insert(int index, int element) {
  if (index >= size || index < 0) return INVALID_POSITION;

  if (elements[index] != 0) return INITIALIZED;

  elements[index] = element;

  return SUCCESS;
}

void Array::print() {
  cout << ("\n[ ");

  for (int i = 0; i < size; i++) {
    cout << elements[i];

    if (i < size - 1) cout << (", ");
  }

  printf(" ]\n");
}

int Array::length() { return size; }

int Array::exclude(int index) {
  if (index >= size || index < 0) return INVALID_POSITION;

  if (elements[index] == 0) return EMPTY;

  elements[index] = 0;

  return SUCCESS;
}

int Array::push(int element) {
  for (int i = 0; i < size; i++) {

    if (elements[i] == 0) {
      elements[i] = element;
      return SUCCESS;
    }
  }

  return ARRAY_FULL;
}

int Array::update(int index, int element) {
  if (index >= size || index < 0) return INVALID_POSITION;

  elements[index] = element;

  return SUCCESS;
}

int Array::reset() {
  for (int i = 0; i < size; i++) {
    elements[i] = 0;
  }

  return SUCCESS;
}
