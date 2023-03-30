#ifndef ARRAY_H
#define ARRAY_H

// # CLASS

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

// ----------------------------------

#endif
