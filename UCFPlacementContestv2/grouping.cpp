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

map<int, long long> hm;

int main() {
  // ifstream cin("groupingi.txt");
  // ofstream cout("groupingo.txt");
  int t;
  cin >> t;
  while (t--) {
    hm.clear();
    int n;
    cin >> n;
    set<int> check;
    vector<int> cows;
    vector<long long> cownum;
    long long total = 0;
    for (int i = 0; i < n; i++) {
      long long a, b;
      cin >> a >> b;
      if (check.find(b) == check.end()) {
        cows.push_back(b);
        check.insert(b);
      }
      hm[b] += a;
      total += a;
    }
    sort(cows.begin(), cows.end());
    for (auto num : cows) {
      cownum.push_back(hm[num]);
    }
    int s = cownum.size();
    long long prefix[s + 1];
    prefix[0] = 0;
    for (int i = 1; i <= s; i++) {
      prefix[i] = prefix[i - 1] + cownum[i - 1];
    }

    int l = 1;
    bool leftstop = false;
    int r = s;
    bool rightstop = false;
    bool works = false;

    while (true) {
      if ((long double)prefix[l] / total < .3) {
        l++;
        if (l == r) {
          cout << -1 << '\n';
          break;
        }
      } else {
        leftstop = true;
      }

      if (((long double)total - prefix[r]) / (long double)total < .3) {
        r--;
        if (r == l) {
          cout << -1 << '\n';
          break;
        }
      } else {
        rightstop = true;
      }

      if (((long double)prefix[r] - prefix[l]) / (long double)total < .3) {
        cout << -1 << '\n';
        break;
      }

      if (leftstop && rightstop) {
        works = true;
        break;
      }
    }
    if (works) {
      cout << cows[l - 1] << " " << cows[r] - 1 << '\n';
    }
  }

  // cout<<'\n';
  return 0;
}
