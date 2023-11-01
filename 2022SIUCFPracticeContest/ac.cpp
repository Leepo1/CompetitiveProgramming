#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  // ifstream cin("aci.txt");
  // ofstream cout("aco.txt");
  long long c;
  cin >> c;
  while (c--) {
    long long answer = 0;
    long long n;
    cin >> n;
    string s;
    cin >> s;

    long long cs[n];

    if (s[n - 1] == 'C') {
      cs[n - 1] = 1;
    } else {
      cs[n - 1] = 0;
    }

    for (long long i = n - 2; i >= 0; i--) {
      if (s[i] == 'C') {
        cs[i] = cs[i + 1] + 1;
      } else {
        cs[i] = cs[i + 1];
      }
    }
    for (long long i = 0; i < n - 1; i++) {
      if (s[i] == 'A')
        answer += cs[i + 1];
    }
    cout << answer << '\n';
  }
  return 0;
}
