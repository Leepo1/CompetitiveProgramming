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
int firstdigit[100005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // ifstream cin("theoremi.txt");
  // ofstream cout("temp.txt");
  int t;
  cin >> t;
  firstdigit[1] = 1;
  long long lastfactorial = 1;
  for (int i = 2; i < 100005; i++) {
    long long temp = i * lastfactorial;
    string u = to_string(temp);
    firstdigit[i] = (int)u[0] - '0';
    lastfactorial = temp;
  }
  while (t--) {
    int n;
    cin >> n;
    cout << firstdigit[n] << '\n';
  }

  return 0;
}
