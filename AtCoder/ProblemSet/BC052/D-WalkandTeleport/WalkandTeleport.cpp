#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {

  // ifstream cin("input.txt");
  long long n;
  cin >> n;
  long long step, tele;
  cin >> step >> tele;
  long long fatigue = 0;
  vector<long long> locations;
  long long currtown = 1;
  for (long long i = 0; i < n; i++) {
    long long a;
    cin >> a;
    if (i == 0)
      currtown = a;
    locations.push_back(a);
  }
  sort(locations.begin(), locations.end());

  for (long long i = 0; i < n; i++) {
    fatigue += min((locations[i] - currtown) * step, tele);
    currtown = locations[i];
  }
  cout << fatigue << '\n';

  return 0;
}
