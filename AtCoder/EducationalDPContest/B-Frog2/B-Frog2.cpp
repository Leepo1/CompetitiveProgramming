#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  ifstream cin("B-Frog2i.txt");
  ofstream cout("B-Frog2o.txt");
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int dp[n];
  dp[0] = 0;
  dp[1] = abs(arr[1] - arr[0]);
  for (int i = 2; i < n; i++) {
    int mini = 1000000000;
    for (int j = 1; j <= k; j++) {
      if (i - j >= 0) {
        mini = min(mini, dp[i - j] + abs(arr[i] - arr[i - j]));
      }
    }

    dp[i] = mini;
  }
  cout << dp[n - 1];
  return 0;
}
