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

  // ifstream cin("legendi.txt");
  //  ofstream cout ("usaco.out")
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s == "0:00") {
      cout << "legend" << '\n';
    } else {
      cout << "!legend" << '\n';
    }
  }

  // cout<<'\n';
  return 0;
}
