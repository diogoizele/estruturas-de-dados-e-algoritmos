#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "array.constants.h"
#include "array.cpp.h"

using namespace std;

void pause() {
  cout << "Press any key to continue";
  while (getchar() != '\n') {}
  getchar();
}

int main() {

  int option, operation;
  Array* array;

  do {
    system("clear");
    cout << "-------------------------------" << endl;
    cout << "*             Array           *" << endl;
    cout << "*                             *" << endl;
    cout << "* 0 - Exit                    *" << endl;
    cout << "* 1 - Create array            *" << endl;
    cout << "-------------------------------" << endl;
    cout << "Enter an option: ";
    fflush(stdin);

    cin >> option;

    if (option == 1) {
      int size = 0;

      cout << "Enter with array length: ";
      cin >> size;

      array = new Array(size);

      do {

        int element, index, response;

        system("clear");
        cout << "-------------------------------" << endl;
        cout << "*      Array - Operations     *" << endl;
        cout << "*                             *" << endl;
        cout << "* 0 - Exit                    *" << endl;
        cout << "* 1 - Print                   *" << endl;
        cout << "* 2 - Insert                  *" << endl;
        cout << "* 3 - Exclude                 *" << endl;
        cout << "* 4 - Push                    *" << endl;
        cout << "* 5 - Update                  *" << endl;
        cout << "* 6 - Reset                   *" << endl;
        cout << "-------------------------------" << endl;
        cout << "Enter an option: ";

        fflush(stdin);
        cin >> operation;

        switch (operation) {
          case 0:
            operation = 0;
            break;
          case 1:
            array->print();
            pause();

            break;
          case 2:

            cout << "Enter with an element: ";
            cin >> element;

            cout << "Insert this element at which index: ";
            cin >> index;

            response = array->insert(index, element);
            if (response == SUCCESS) {
              cout << "Success to insert!" << endl;
            } else {
              cout << "Failed to insert!" << endl;
            }

            pause();
            break;
          case 3:

            cout << "Enter with index of removed element: ";
            cin >> index;

            response = array->exclude(index);
            if (response == SUCCESS) {
              cout << "Success to exclude!" << endl;
            } else {
              cout << "Failed to exclude!" << endl;
            }

            pause();

            break;
          case 4:
            cout << "Enter with an element: ";
            cin >> element;

            response = array->push(element);
            if (response == SUCCESS) {
              cout << "Success to push!" << endl;
            } else {
              cout << "Failed to push!" << endl;
            }

            pause();

            break;
          case 5:
            cout << "Enter with an new element: ";
            cin >> element;

            cout << "Enter with index by element you want update: ";
            cin >> index;

            response = array->update(index, element);
            if (response == SUCCESS) {
              cout << "Success to update!" << endl;
            } else {
              cout << "Failed to update!" << endl;
            }

            pause();

            break;
          case 6:

            response = array->reset();
            if (response == SUCCESS) {
              cout << "Success to reset array!" << endl;
            } else {
              cout << "Failed to reset!" << endl;
            }

            pause();

            break;
          default:
            cout << endl << "Unknown operation " << operation;
            pause();
        }
      } while (operation != 0);
    }

  } while (option != 0);

  return 0;
}
