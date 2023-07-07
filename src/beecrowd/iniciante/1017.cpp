/**
 * exercise 1017
 * url: https://www.beecrowd.com.br/judge/pt/problems/view/1017
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {

  int h, km;

  cin >> h >> km;

  double s, l;

  cout << fixed;
  cout.precision(3);

  s = km * h;
  l = s / 12;

  cout << l << endl;

  return 0;
}
