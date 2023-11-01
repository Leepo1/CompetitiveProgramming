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

  // ifstream cin("performancei.txt");
  // ofstream cout ("usaco.out")
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    int pos[n + 5];
    for (int i = 1; i <= n; i++) {
      int a;
      cin >> a;
      pos[i] = a;
    }
    for (int i = 0; i < q; i++) {
      int f, s;
      cin >> f >> s;
      int temp = pos[f];
      pos[f] = pos[s];
      pos[s] = temp;
    }
    for (int i = 1; i <= n; i++) {
      cout << pos[i] << " ";
    }
    cout << '\n';
  }

  // cout<<'\n';
  return 0;
}
