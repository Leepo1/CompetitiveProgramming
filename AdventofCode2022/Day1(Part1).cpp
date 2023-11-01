#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ifstream cin("Day1(Part1)i.txt");
  ofstream cout("Day1(Part1)o.txt");
  cout << "hi";
  string s;
  int curr = 0;
  vector<long long> v;
  while (getline(cin, s)) {
    if (s == "") {
      v.push_back(curr);
      curr = 0;
    } else {
      curr += stoi(s);
    }
  }
  sort(v.begin(), v.end());
  int l = v.size();
  long long answer = v[l - 1] + v[l - 2] + v[l - 3];
  cout << answer << '\n';
  return 0;
}
