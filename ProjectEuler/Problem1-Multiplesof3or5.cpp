#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int sum = 0;
  for (int i = 0; i < 1000; i++) {
    if (i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }
  cout << sum << '\n';

  // Also O(1) solution if you do sum of arithmetic sequence: ∑(3) + ∑(5) -
  // ∑(15) -> avoid overcounting.
  return 0;
}
