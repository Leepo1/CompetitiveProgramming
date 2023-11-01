#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  // formula for sum of the first n numbers n(n+1)/2
  // formula for sum of the first n squares n(n+1)(2n+1)/6
  // Also could be naive prob;
  long long squares = (100) * (101) * (201) / 6;
  long long reg = (100 * 101 * 100 * 101) / 4;
  cout << reg - squares << '\n';

  return 0;
}
