#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {

  ifstream cin("backforth.in");
  ofstream cout("backforth.out");
  vector<int> fbuckets;
  vector<int> sbuckets;
  set<int> possible;
  int first = 1000;
  int a;
  for (int i = 0; i < 10; i++) {
    cin >> a;
    fbuckets.push_back(a);
  }
  for (int i = 0; i < 10; i++) {
    cin >> a;
    sbuckets.push_back(a);
  }

  for (int i = 0; i < fbuckets.size(); i++) {
    fbuckets.erase(fbuckets.begin() + i);
    sbuckets.push_back(fbuckets[i]);
    first = first - fbuckets[i];
    for (int j = 0; j < sbuckets.size(); j++) {
      sbuckets.erase(sbuckets.begin() + j);
      fbuckets.push_back(sbuckets[j]);
      first = first + sbuckets[j];
      for (int g = 0; g < fbuckets.size(); g++) {
        fbuckets.erase(fbuckets.begin() + g);
        sbuckets.push_back(fbuckets[g]);
        first = first - fbuckets[g];
      }
      for (int h = 0; h < sbuckets.size(); h++) {
        sbuckets.erase(sbuckets.begin() + h);
        fbuckets.push_back(sbuckets[h]);
        first = first + sbuckets[h];
      }
    }
    possible.insert(first);
  }
  cout << possible.size();
  return 0;
}
