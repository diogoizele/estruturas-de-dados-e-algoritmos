/**
 * exercise 1019
 * url: https://www.beecrowd.com.br/judge/pt/problems/view/1019
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

#define MINUTE 60
#define HOUR 60

using namespace std;

int main() {

  int time, time_tmp, time_result;

  cin >> time;

  time_tmp = time;

  time_result = time_tmp / (MINUTE * HOUR);
  cout << time_result << ":";
  time_tmp %= (MINUTE * HOUR);

  time_result = time_tmp / MINUTE;
  cout << time_result << ":";
  time_tmp %= MINUTE;

  cout << time_tmp << endl;

  return 0;
}
