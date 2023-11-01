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
const int MAX_N = 100000;
int arr[MAX_N];

struct Node {
  int l, r;
  int sum;
  Node *left, *right;

  Node(int L, int R) {
    l = L;
    r = R;
    sum = 0;
    left = nullptr;
    right = nullptr;
  }

  void build(int L, int R) {
    l = L;
    r = R;
    if (L == R) {
      sum = arr[l];
      return;
    }
    int m = L + (R - L) / 2;

    left = new Node(l, m);
    right = new Node(m + 1, r);
    sum = left->sum + right->sum;
  }

  void update(int x, int v) {
    if (l > x || r < x)
      return;
    if (l == r) {
      sum += v;
      return;
    }
    int m = l + (r - l) / 2;
    left->update(l, m);
    right->update(m + 1, r);
    sum = left->sum + right->sum;
  }

  int query(int dl, int dr) {
    if (l > dr || r < dl)
      return 0;
    if (dl <= l && dr >= r)
      return sum;
    int m = l + (r - l) / 2;
    return left->query(l,m) + right->query(m+1,r);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // ifstream cin ("usaco.in");
  // ofstream cout ("usaco.out");
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    Node *start = new Node(0, n - 1);
    start->build(0, n - 1);
    for (int i = 0; i < q; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      if (a == 1) {
        start->update(b, c);
      } else {
        cout << start->query(b,c) << '\n';
      }
    }
  }
  return 0;
}
