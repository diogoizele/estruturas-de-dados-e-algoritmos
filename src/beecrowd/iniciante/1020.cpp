/**
 * exercise 1020
 * url: https://www.beecrowd.com.br/judge/pt/problems/view/1020
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

#define YEAR 365
#define MONTH 30

using namespace std;

int main() {

  int age, age_tmp, age_result;

  cin >> age;

  age_tmp = age;

  age_result = age_tmp / YEAR;
  cout << age_result << " ano(s)" << endl;
  age_tmp %= YEAR;

  age_result = age_tmp / MONTH;
  cout << age_result << " mes(es)" << endl;
  age_tmp %= MONTH;

  age_result = age_tmp;
  cout << age_result << " dia(s)" << endl;

  return 0;
}
