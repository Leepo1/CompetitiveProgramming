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
using ll = long long;
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

// Initial array and ST array
const int MAX_N = 100000;
int arr[MAX_N], t[MAX_N];

// Fills in all values of the ST
void build(int v, int cl, int cr) {
  if (cl == cr) {
    t[v] = arr[cl];
  } else {
    int cm = (cl + cr) / 2;
    build(v * 2, cl, cm);
    build(v * 2 + 1, cm + 1, cr);
    t[v] = t[2 * v] + t[2 * v + 1];
  }
}

int sum(int v, int cl, int cr, int dl, int dr) {
  if (cr < dl || cl > dr)
    return 0;
  if (dl <= cl && cr <= dr)
    return t[v];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // ifstream cin ("usaco.in");
  // ofstream cout ("usaco.out");

  return 0;
}
