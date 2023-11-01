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
  ifstream cin("hopscotch.in");
  ofstream cout("hopscotch.out");

  int r, c, k;
  cin >> r >> c >> k;
  int dp[r][c];
  int arr[r][c];
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> arr[i][j];
      dp[i][j] = 0;
    }
  }
  dp[0][0] = 1;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      for (int k = i + 1; k < r; k++) {
        for (int g = j + 1; g < c; g++) {
          if (arr[i][j] != arr[k][g])
            dp[k][g] = (dp[k][g] + dp[i][j]) % (1000000007);
        }
      }
    }
  }
  cout << dp[r - 1][c - 1] << '\n';
  return 0;
}
