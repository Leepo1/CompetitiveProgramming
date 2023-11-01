#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[10005][105][105];
int main(){
  ll n,f,s; cin>>n>>f>>s;

  for(int i=0;i<=n;i++){
    for(int j=0;j<=f;j++){
      for(int k=0;k<=s;k++){
        dp[i][j][k] = 0;
        if(i==0) dp[i][j][k] = 0;
        if(j==0 || k == 0) dp[i][j][k] = 0;
      }
    }
  }
  
  ll ff[n];
  ll ss[n];
  for(int i=0;i<n;i++){
    cin>>ff[i];
    cin>>ss[i];
  }

  for(int i=0;i<n;i++){
    for(int j=1;j<=f;j++){
      for(int k=1;k<s;k++){
        dp[i+1][j][k] = max(max(dp[i][j][k], dp[i][j-1][k]+ff[i]), dp[i][j][k-1]);
      }
    }
  }
  ll ans;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=f;j++){
      for(int k=0;k<=s;k++){
        ans = max(ans, dp[i][j][k]);
      }
    }
  }
  cout<<ans;
    
}