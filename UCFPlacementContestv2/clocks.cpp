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
map<char, string> rep;

int main() {
  rep['0'] = "OOOOOO...OO...OO...OOOOOO";
  rep['1'] = "..O....O....O....O....O..";
  rep['2'] = "OOOOO....OOOOOOO....OOOOO";
  rep['3'] = "OOOOO....OOOOOO....OOOOOO";
  rep['4'] = "O...OO...OOOOOO....O....O";
  rep['5'] = "OOOOOO....OOOOO....OOOOOO";
  rep['6'] = "OOOOOO....OOOOOO...OOOOOO";
  rep['7'] = "OOOOO....O....O....O....O";
  rep['8'] = "OOOOOO...OOOOOOO...OOOOOO";
  rep['9'] = "OOOOOO...OOOOOO....OOOOOO";
  rep[':'] = "..O....O.........O....O..";
  // ifstream cin("clocksi.txt");
  // ofstream cout("clockso.txt");
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    for (int r = 0; r < 5; r++) {
      for (int l = 0; l < s.size(); l++) {
        for (int j = 0; j < 5; j++) {
          cout << rep[s[l]][5 * r + j];
        }
        if (l != s.size() - 1)
          cout << ".";
      }
      cout << '\n';
    }
    cout << '\n';
  }

  // cout<<'\n';
  return 0;
}
