/**
 * exercise 1021
 * url: https://www.beecrowd.com.br/judge/pt/problems/view/1021
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

#define LENGTH 6

using namespace std;

int main() {

  double available_bills[LENGTH] = {100, 50, 20, 10, 5, 2};
  double available_coins[LENGTH] = {1.0, .5, .25, .1, .05, .01};

  double value, value_tmp;
  cin >> value;

  if (value < 0 || value > 1000000.00) return 1;

  value_tmp = value;

  cout << fixed;
  cout.precision(2);

  cout << "NOTAS:" << endl;
  for (int i = 0; i < LENGTH; i++) {
    int divide = value_tmp / available_bills[i];

    cout << divide << " nota(s) de R$ " << available_bills[i] << endl;
    value_tmp = ((int)value_tmp) % ((int)available_bills[i]);
  }

  value_tmp = (value_tmp + (value - ((int)value))) * 100;

  cout << "MOEDAS:" << endl;
  for (int i = 0; i < LENGTH; i++) {
    int decimal_base_coin = (available_coins[i] * 100);
    int divide = value_tmp / decimal_base_coin;

    cout << divide << " moeda(s) de R$ " << available_coins[i] << endl;
    value_tmp = ((int)value_tmp) % decimal_base_coin;
  }

  return 0;
}
