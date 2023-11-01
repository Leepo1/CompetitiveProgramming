#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  ifstream cin("input.txt");
  string line;
  string number = "";
  while (cin >> line) {
    number += line;
  }
  cout << number << '\n';
  // Could use prefix-product idea - no need though
  long long answer = 1;
  for (int i = 0; i <= number.size() - 13; i++) {
    long long product = 1;
    for (int j = 0; j <= 12; j++) {
      product *= number[i + j] - '0';
    }
    answer = max(answer, product);
  }
  cout << answer << '\n';
  return 0;
}
