/**
 * exercise 1018
 * url: https://www.beecrowd.com.br/judge/pt/problems/view/1018
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

#define LENGTH 7

using namespace std;

int main() {

  int available_bills[LENGTH] = {100, 50, 20, 10, 5, 2, 1};

  int value;
  cin >> value;

  if (value < 0 || value > 1000000) return 1;

  cout << value << endl;

  for (int i = 0; i < LENGTH; i++) {
    int divide = value / available_bills[i];

    cout << divide << " nota(s) de R$ " << available_bills[i] << ",00" << endl;
    value = value % available_bills[i];
  }

  return 0;
}
