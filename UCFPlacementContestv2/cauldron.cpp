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
#define ii pair<int, int>
#define pc pair<char, int>
int main() {

  // ifstream cin("cauldroni.txt");
  // ofstream cout ("usaco.out")
  int t;
  cin >> t;
  bool visited[100005];
  while (t--) {
    for (int i = 0; i < 100005; i++)
      visited[i] = false;
    int spells, init, d;
    cin >> spells >> init >> d;
    pc edges[spells];
    for (int i = 0; i < spells; i++) {
      char a;
      int num;
      cin >> a >> num;
      edges[i].first = a;
      edges[i].second = num;
    }
    int answer = -1;
    queue<ii> q;
    q.push(make_pair(0, init));
    while (!q.empty()) {
      ii temp = q.front();
      q.pop();
      if (temp.second == d) {
        answer = temp.first;
        break;
      }
      if (visited[temp.second]) {
        continue;
      }
      visited[temp.second] = true;
      for (auto u : edges) {
        if (u.first == 'M') {
          if (temp.second + u.second > 100000)
            continue;
          if (visited[temp.second + u.second])
            continue;
          q.push(make_pair(temp.first + 1, temp.second + u.second));
        } else if (u.first == 'V') {
          if (temp.second - u.second < 0)
            continue;
          if (visited[temp.second - u.second])
            continue;
          q.push(make_pair(temp.first + 1, temp.second - u.second));
        } else {
          if (temp.second > 100000 / u.second)
            continue;
          if (visited[temp.second * u.second])
            continue;
          q.push(make_pair(temp.first + 1, temp.second * u.second));
        }
      }
    }
    cout << answer << '\n';
  }

  // cout<<'\n';
  return 0;
}
