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

  // ifstream cin("input.in");
  // ofstream cout("output.out");
  int n, q;
  cin >> n >> q;
  char grid[n][n];
  int prefix[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
      prefix[i][j] = 0;
      if (grid[i][j] == '*')
        prefix[i][j] = 1;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i - 1 < 0 && j - 1 < 0) {
        continue;
      }
      if (i - 1 < 0) {
        prefix[i][j] = prefix[i][j - 1] + prefix[i][j];
        continue;
      }
      if (j - 1 < 0) {
        prefix[i][j] = prefix[i - 1][j] + prefix[i][j];
        continue;
      }
      prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] -
                     prefix[i - 1][j - 1] + prefix[i][j];
    }
  }

  while (q--) {
    int x, y, r, c;
    cin >> x >> y >> r >> c;
    x--;
    y--;
    r--;
    c--;
    int whole, left, top, lefttop;
    whole = prefix[r][c];
    if (x - 1 < 0) {
      top = 0;
      lefttop = 0;
    }
    if (y - 1 < 0) {
      left = 0;
      lefttop = 0;
    }
    if (x - 1 >= 0) {
      top = prefix[x - 1][c];
    }
    if (y - 1 >= 0) {
      left = prefix[r][y - 1];
    }
    if (x - 1 >= 0 && y - 1 >= 0) {
      lefttop = prefix[x - 1][y - 1];
    }
    cout << whole - left - top + lefttop << '\n';
  }

  return 0;
}
