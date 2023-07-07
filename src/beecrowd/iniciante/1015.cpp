/**
 * exercise 1015
 * url: https://www.beecrowd.com.br/judge/pt/problems/view/1015
 */

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {

  cout << fixed;
  cout.precision(4);

  double x1, x2, y1, y2, d;

  cin >> x1 >> y1 >> x2 >> y2;

  d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

  cout << d << endl;

  return 0;
}
