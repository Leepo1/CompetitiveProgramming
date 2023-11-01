#include <algorithm>
#include <iostream>

using namespace std;

int main() {

  int fib1 = 1;
  int fib2 = 2;
  long long sum = 2;
  while (fib2 <= 4000000) {
    int fib3 = fib1 + fib2;
    if (fib3 % 2 == 0)
      sum += fib3;
    fib1 = fib2;
    fib2 = fib3;
  }
  cout << sum << '\n';

  return 0;
}
