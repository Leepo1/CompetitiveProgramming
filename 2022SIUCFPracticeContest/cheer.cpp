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

int main() {

  // ifstream cin ("usaco.in")
  // ofstream cout ("usaco.out")
  int c;
  cin >> c;
  while (c--) {
    int n;
    cin >> n;
    vector<long long> heights;
    long long a;
    while (n--) {
      cin >> a;
      heights.push_back(a);
    }
    sort(heights.begin(), heights.end());
    long long tower = heights[heights.size() - 1];
    long long prev = heights[heights.size() - 1];
    for (int i = heights.size() - 2; i >= 0; i--) {
      if (prev - heights[i] >= 2) {
        tower += heights[i];
        prev = heights[i];
      }
    }
    cout << tower << '\n';
  }

  // cout<<'\n';
  return 0;
}
