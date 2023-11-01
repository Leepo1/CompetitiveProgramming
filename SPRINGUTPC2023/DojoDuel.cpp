#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

struct sorceror {
  int dskill;
  int mskill;
  int kskill;
  int speed;
  string name;
};
bool cmp(sorceror &a, sorceror &b) {
  if (b.dskill == a.dskill) {
    if (b.mskill == a.mskill) {
      if (b.kskill == a.kskill) {
        if (b.speed == a.speed) {
          return b.name < a.name;
        }
        return b.speed > a.speed;
      }
      return b.kskill > a.kskill;
    }
    return b.mskill > a.mskill;
  }
  return b.dskill > a.dskill;
}
int main() {
  // ifstream cin("input.txt");

  int n;
  cin >> n;
  vector<sorceror> tourn;
  for (int i = 0; i < n; i++) {
    sorceror temp;
    cin >> temp.name >> temp.kskill >> temp.mskill >> temp.speed >> temp.dskill;
    tourn.push_back(temp);
  }
  sort(tourn.begin(), tourn.end(), cmp);
  reverse(tourn.begin(), tourn.end());
  for (int i = 0; i < tourn.size(); i++) {
    cout << tourn[i].name << '\n';
  }

  return 0;
}
