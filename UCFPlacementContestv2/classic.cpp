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

  // ifstream cin ("usaco.in")
  // ofstream cout ("usaco.out")
  int t;
  cin >> t;
  while (t--) {
    int sols;
    int r, c;
    cin >> r >> c;
    int grid[r][c];
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cin >> grid[i][j];
      }
    }
  }

  // cout<<'\n';
  return 0;
}
