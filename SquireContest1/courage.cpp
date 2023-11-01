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
int arr[100005];
bool issquare[1000005];
void setup() {
  for (int i = 0; i * i < 100005; i++) {
    issquare[i * i] = true;
  }
}
struct Node {
  int l, r;
  int courage = 0;
  int ns = 0;
  Node *left = nullptr;
  Node *right = nullptr;
  void build(int L, int R) {
    l = L;
    r = R;
    if (l == r) {
      courage = arr[l];
      ns = issquare[courage];
      return;
    }
    int m = l + (r - l) / 2;
    left = new Node();
    right = new Node();
    left->build(l, m);
    right->build(m + 1, r);
    if (issquare[courage]) {
      ns = left->ns + right->ns;
    }
  }
  void update(int x, int prod) {
    if (l > x || r < x)
      return;
    if (l == r) {
      courage *= prod;
      ns = issquare[courage];
      return;
    }

    left->update(x, prod);
    right->update(x, prod);
    ns = left->ns + right->ns;
  }

  int query(int dl, int dr) {
    if (l > dr || r < dl)
      return 0;
    ;
    if (dl <= l && r <= dr)
      return ns;

    return left->query(dl, dr) + right->query(dl, dr);
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ifstream cin("couragei.txt");
  // ofstream cout ("usaco.out");

  int t;
  cin >> t;
  setup();
  while (t--) {
    int n, q;
    cin >> n >> q;
    Node *start = new Node();
    start->build(0, n - 1);
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    for (int i = 0; i < q; i++) {
      int a, b;
      cin >> a >> b;
      start->update(a - 1, b);
      cout << start->query(a - 1, b - 1) << '\n';
    }
  }
  return 0;
}
