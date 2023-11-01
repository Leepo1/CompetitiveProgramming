#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
int n;
int dist[15][15];
int dp [80000][15];

int currstart = 0;

int recurse(int mask, int ending){
  if(dp[mask][ending] != INT_MAX) return dp[mask][ending];
  if(__builtin_popcount(mask) == 1) {
    return dist[ending][currstart];
  }
  int postmask =  mask - (1 << ending);
  for(int i = 0; i < n; i++){
    if(((1 << i ) & postmask) == 0) continue;
    else dp[mask][ending] = min(dp[mask][ending] , recurse(postmask , i) + dist[i][ending]);
  }
  return dp[mask][ending];
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // ifstream cin ("usaco.in"); ofstream cout ("usaco.out");
    
    cin>> n;
    int answer = INT_MAX; 
    for(int i = 0; i < (1 << n); i++){
      for(int j = 0; j < n ; j++){
        dp[i][j] = INT_MAX;
       }
    }
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        int temp; cin >> temp;
        dist[i][j] = temp;
      }
    }

    cout << recurse((1 << n) - 1, 0) << '\n';
    
  return 0;
}
