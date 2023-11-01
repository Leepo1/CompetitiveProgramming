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
const int MAX_N = 1e7 + 5;
int arr[MAX_N];

struct Node {
  int l, r;
  long long sum = 0;
  Node *left = nullptr;
  Node *right = nullptr;

  void build(int L, int R) {
    l = L;
    r = R;
    if (l == r) {
      sum = arr[l];
      return;
    }
    int m = l + (r - l) / 2;

    left = new Node();
    right = new Node();

    left->build(l, m);
    right->build(m + 1, r);
    sum = left->sum + right->sum;
  }

  long long query(int dl, int dr) {
    // cout << l << " " << r << " " << dl << " " << dr << endl;
    if (r < dl || l > dr)
      return 0;
    if (dl <= l && r <= dr)
      return sum;
    int m = l + (r - l) / 2;

    return (left->query(dl, dr) + right->query(dl, dr));
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  Node *start = new Node();

  start->build(0, n - 1);

  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    cout << start->query(a - 1, b - 1) << endl;
  }

  return 0;
}
