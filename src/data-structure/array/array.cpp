#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "array.constants.h"
#include "array.cpp.h"

using namespace std;

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
