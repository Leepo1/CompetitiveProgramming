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
int n;
bool used[n];
vector<int> nums;
void recurse(int n, int k, int lst) {
  if (k == n) {
    // Do what you please with permutation
  }
  for (int i = lst + 1; i < n; i++) {
    if (used[i])
      continue;
    nums.push_back(i);
    used[i] = true;
    recurse(n, k + 1, iz);
    used[i] = false;
    nums.pop_back();
  }
}
// Subsets
// Prob could also be used for combinations by using popcount
for (int mask = 0; mask < (1 << n); mask++) {
  long long sum_of_this_subset = 0;
  for (int i = 0; i < n; i++) {
    if (mask & (1 << i)) {
      sum_of_this_subset += a[i];
    }
  }
  if (sum_of_this_subset == S) {
    puts("YES");
    return 0;
  }
}
puts("NO");
int main() {

  // ifstream cin ("usaco.in")
  // ofstream cout ("usaco.out")

  // cout<<'\n';
  return 0;
}
