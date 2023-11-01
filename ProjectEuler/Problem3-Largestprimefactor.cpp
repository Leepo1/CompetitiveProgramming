#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
int isprime(int num) {
  if (num == 2)
    return true;
  if (num % 2 == 0)
    return false;
  for (int i = 3; i < num; i += 2) {
    if (num % i == 0)
      return false;
  }
  return true;
}
int main() {
  int answer = 0;
  for (int i = 2; i < sqrt(600851475143); i++) {
    if (600851475143 % i == 0 && isprime(i))
      answer = i;
  }
  cout << answer << '\n';
  return 0;
}
