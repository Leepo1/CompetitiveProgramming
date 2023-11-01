#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
bool isprime(long long test) {
  if (test == 2)
    return true;
  if (test % 2 == 0)
    return false;
  for (int i = 3; i < test; i += 2) {
    if (test % i == 0)
      return false;
  }
  return true;
}
int main() {
  long long curr = 2;
  long long many = 0;
  while (many < 10001) {
    if (isprime(curr))
      many++;
    curr++;
  }
  cout << curr - 1 << '\n';

  return 0;
}
