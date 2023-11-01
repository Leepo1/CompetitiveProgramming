/*
ID: Sameer Bhatti
Grade:8
Task:
LANG: C++11
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define INF 2000000000
using namespace std;
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>

int main() {

  ifstream cin("maxcross.in");
  ofstream cout("maxcross.out");
  int n, k, b;
  cin >> n >> k >> b;
  int broksignals[n + 5];
  for (int i = 0; i < n + 5; i++)
    broksignals[i] = 0;
  for (int i = 0; i < b; i++) {
    int a;
    cin >> a;
    broksignals[a] = 1;
  }
  for (int i = 1; i < n + 5; i++)
    broksignals[i] += broksignals[i - 1];
  int answer = b;
  for (int i = 1; i <= n - k + 1; i++) {
    answer = min(answer, broksignals[i + k - 1] - broksignals[i - 1]);
  }
  cout << answer << '\n';
  return 0;
}
