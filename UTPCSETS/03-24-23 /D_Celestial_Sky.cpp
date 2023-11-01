#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
int stars[1000][1000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,m,q; cin >> n >> m >> q;
    for(int i = 0; i < n; i++){
        int x,y; cin >> x >> y;
        stars[x][y]++;
    }
    for(int i = 0; i < m; i++){
      int x,y; cin >> x >> y;
      for(int i = max(0, x - 1); i <= x + 1; i++){
        for(int j = max(0,y - 1); j <= y + 1; j++){
          stars[i][j] = 0;
        }
      }
    }
    for(int i = 0; i < 1000; i++){
      for(int j = 0; j < 1000; j++){
        if(i != 0){
          stars[i][j] += stars[i - 1][j];
        }
        if(j != 0){
          stars[i][j] += stars[i][j - 1];
        }
        if(i != 0 && j != 0) stars[i][j] -= stars[i - 1][j - 1];
      }
    }
    for(int i = 0; i < q; i++){
      int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
      int answer = stars[x2][y2];
      if(x1 != 0) answer -= stars[x1 - 1][y2];
      if(y1 != 0) answer -= stars[x2][y1 -1];
      if(x1 != 0 && y1 != 0) answer += stars[x1 -1][y1 -1];
      cout << answer << '\n';
    }
  return 0;
}

