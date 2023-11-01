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
typedef long long ll;
typedef pair<long long, long long> pl;

ll n, m;
pl intervals[100005];

bool works(ll M) {
  ll start = intervals[0].first;
  int interval = 0;
  for (ll i = 1; i < n; i++) {
    ll next = start + M;
    if (next > intervals[m - 1].second)
      return false;
    for (ll i = interval; i < m; i++) {

      if (next > intervals[i].second) {
        interval = i + 1;
      } else {
        break;
      }
    }
    next = max(next, intervals[interval].first);
    start = next;
  }
  return true;
}

int main() {

  ifstream cin("socdist.in");
  ofstream cout("socdist.out");
  cin >> n >> m;
  for (ll i = 0; i < m; i++) {
    cin >> intervals[i].first >> intervals[i].second;
  }
  sort(intervals, intervals + m);

  ll L = 0, R = intervals[m - 1].second - intervals[0].first;
  while (L < R) {
    // cout << L << " " << R << '\n';
    ll M = L + (R - L + 1) / 2;
    if (works(M)) {
      L = M;
    } else {
      R = M - 1;
    }
  }
  cout << L << '\n';

  return 0;
}
