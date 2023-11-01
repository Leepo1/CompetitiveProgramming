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
#define pi pair<long long, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
const int MAX_N = 1e7 + 5;
int arr[MAX_N];

bool isprime[MAX_N];
void sieve() {
  for (int i = 2; i < MAX_N; i++)
    isprime[i] = true;
  for (int i = 2; i * i < MAX_N; i++) {
    if (!isprime[i])
      continue;
    for (int j = i * i; j < MAX_N; j += i) {
      isprime[j] = false;
    }
  }
}

struct Node {
  int l, r;
  long long sum = 0;
  int np = 0;
  Node *left = nullptr;
  Node *right = nullptr;
  void build(int L, int R) {
    l = L;
    r = R;
    if (l == r) {
      sum = arr[l];
      np = isprime[sum];
      return;
    }
    int m = l + (r - l) / 2;
    left = new Node();
    right = new Node();
    left->build(l, m);
    right->build(m + 1, r);
    sum = left->sum + right->sum;
    np = left->np + right->np;
  }
  void update(int x, int add) {
    if (l > x || r < x)
      return;
    if (l == r) {
      sum += add;
      np = isprime[sum];
      return;
    }

    left->update(x, add);
    right->update(x, add);
    sum = left->sum + right->sum;
    np = left->np + right->np;
  }
  pi comp(pi a, pi b) {
    return make_pair(a.first + b.first, a.second + b.second);
  }
  pi query(int dl, int dr) {
    if (l > dr || r < dl)
      return make_pair(0, 0);
    if (dl <= l && r <= dr)
      return make_pair(sum, np);

    return comp(left->query(dl, dr), right->query(dl, dr));
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // ifstream cin("orangesi.txt");
  sieve();
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    Node *start = new Node();
    start->build(0, n - 1);
    for (int i = 0; i < q; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      if (a == 1) {
        start->update(b - 1, c);
      } else {
        pi answer = start->query(b - 1, c - 1);
        cout << answer.first << " " << answer.second << '\n';
      }
    }
  }

  return 0;
}
