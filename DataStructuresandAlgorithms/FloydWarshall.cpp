#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int adj[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      adj[i][j] = 100000;
    }
    adj[i][i] = 0;
  }

  for (int i = 0; i < m; i++) {
    int x, y, d;
    cin >> x >> y >> d;
    adj[x][y] = d;
    adj[y][x] = d;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        adj[i][j] = min(adj[i][k] + adj[k][j], adj[i][j]);
      }
    }
  }

  return 0;
}
