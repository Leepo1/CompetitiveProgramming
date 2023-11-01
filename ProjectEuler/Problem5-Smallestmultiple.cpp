#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
int main() {
  long long curr = 1;
  for (long long i = 2; i <= 20; i++) {
    curr = curr * i / (gcd(curr, i));
  }
  cout << curr << '\n';

  // Can do on paper - prime factorization idea
  // Used a*b = lcm(a,b)/gcd(a,b)
  return 0;
}
