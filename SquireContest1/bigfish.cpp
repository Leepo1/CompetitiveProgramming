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
map<long long, int> m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // ifstream cin("bigfishi.txt");
  // ofstream cout ("usaco.out");
  int t;
  cin >> t;
  while (t--) {
    m.clear();
    int n;
    cin >> n;
    set<long long> s;
    int total = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      s.insert(a);
      m[a]++;
      total++;
    }
    bool stop = false;
    while (true) {
      long long u = *s.begin();
      // cout << u << '\n';
      if (s.upper_bound(2 * u) == s.end()) {
        break;
      }
      long long value = *s.upper_bound(2 * u);
      m[value]--;
      m[u]--;
      total -= 2;
      if (m[value] == 0)
        s.erase(s.upper_bound(2 * u));
      if (m[u] == 0) {
        s.erase(s.begin());
      }
      s.insert(u + value);
      m[u + value]++;
      total++;
    }
    cout << total << '\n';
    for (auto u : s) {
      for (int i = 0; i < m[u]; i++) {
        cout << u << '\n';
      }
    }
  }
  return 0;
}
