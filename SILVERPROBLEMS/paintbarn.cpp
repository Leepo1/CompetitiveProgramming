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
int paint[1001][1001];
int main() {

  ifstream cin("paintbarn.in");
  ofstream cout("paintbarn.out");
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    paint[sy][sx]++;
    paint[sy][ex]--;
    paint[ey][sx]--;
    paint[ey][ex]++;
  }
  int answer = 0;
  for (int i = 0; i < 1001; i++) {
    for (int j = 0; j < 1001; j++) {
      if (i > 0)
        paint[i][j] += paint[i - 1][j];
      if (j > 0)
        paint[i][j] += paint[i][j - 1];
      if (i > 0 && j > 0)
        paint[i][j] -= paint[i - 1][j - 1];
      if (paint[i][j] == k)
        answer++;
    }
  }
  cout << answer << '\n';
  // cout<<'\n';
  return 0;
}
