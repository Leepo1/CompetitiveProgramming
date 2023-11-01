#include <algorithm>
#include <iostream>

using namespace std;
int main() {
  int h, w;
  cin >> h >> w;
  char grid[h][w];
  int dp[h][w];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> grid[i][j];
      dp[i][j] = 0;
    }
  }
  dp[0][0] = 1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (grid[i][j] == '#')
        continue;
      if (i - 1 >= 0 && grid[i - 1][j] != '#') {
        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % 1000000007;
      }
      if (j - 1 >= 0 && grid[i][j - 1] != '#') {
        dp[i][j] = (dp[i][j] + dp[i][j - 1]) % 1000000007;
      }
    }
  }
  cout << dp[h - 1][w - 1];
  return 0;
}
