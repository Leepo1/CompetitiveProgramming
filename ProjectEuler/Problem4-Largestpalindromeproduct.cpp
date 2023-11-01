#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
bool ispalindrome(int num) {
  string check = to_string(num);
  for (int i = 0; i < check.size() / 2; i++) {
    if (check[i] != check[check.size() - 1 - i])
      return false;
  }
  return true;
}
int main() {
  int answer = 0;
  for (int i = 100; i <= 999; i++) {
    for (int j = 100; j <= 999; j++) {
      if (ispalindrome(i * j))
        answer = max(answer, i * j);
    }
  }
  cout << answer << '\n';

  return 0;
}
