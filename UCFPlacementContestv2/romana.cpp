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
vector<long long> nums;
int main() {

  // ifstream cin("romanai.txt");
  // ofstream cout("romanao.txt");
  string s = "123456789";
  sort(s.begin(), s.end());

  do {
    nums.push_back(stoi(s));
  } while (next_permutation(s.begin(), s.end()));

  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    int place = lower_bound(nums.begin(), nums.end(), n) - nums.begin();
    cout << nums[place] - n << '\n';
  }

  // cout<<'\n';
  return 0;
}
