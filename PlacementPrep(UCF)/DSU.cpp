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

const int maxn = 2e5 + 5;

int parent[maxn];
int sz[maxn];

int comp(int a) {
  if (parent[a] == a)
    return a;

  parent[a] = comp(parent[a]);
  return parent[a];
}

bool unite(int a, int b) {
  a = comp(a);
  b = comp(b);
  if (a == b)
    return false;
  if (sz[a] < sz[b])
    swap(a, b);
  sz[a] += sz[b];
  parent[b] = a;
  return true;
}

int main() {
  for (int i = 0; i < maxn; i++) {
    parent[i] = i;
    sz[i] = 1;
  }
  int n, m;
  cin >> n >> m;
  int components = n;
  int ms = 1;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if (unite(a, b)) {
      components--;
      a = comp(a);
      b = comp(b);
      ms = max(ms, max(sz[a], sz[b]));
    }

    cout << components << " " << ms << '\n';
  }

  // ifstream cin ("usaco.in")
  // ofstream cout ("usaco.out")

  // cout<<'\n';
  return 0;
}
