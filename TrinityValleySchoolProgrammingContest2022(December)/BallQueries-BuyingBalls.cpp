#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("BallQueries-BuyingBallsi.txt");
  ofstream cout("BallQueries-BuyingBallso.txt");
  int n; cin>> n;
  int ball[n];
  int cost[n];
  for(int i=0; i<n; i++){
    cin>> ball[i] >> cost[i];
  }
  int amount; cin>> amount;
  int dp[n][amount+5];
  for(int i=0; i<n; i++){
    dp[i][0]=0;
    for(int j=1; j<=amount; j++){
        if(ball[i]>j){
          if(i==0){
            dp[0][j]=-1;
          }else{
            dp[i][j]=dp[i-1][j];
          }
        }else{

          if(dp[i][j-ball[i]]==-1){
            if(i==0){
              dp[i][j]=-1;
              continue;
            }
            dp[i][j]= dp[i-1][j];
            continue;
          }
          if(i==0){
            dp[i][j]= dp[i][j-ball[i]]+cost[i];
            continue;
          }
          if(dp[i-1][j]==-1){
            dp[i][j]= dp[i][j-ball[i]]+cost[i];
            continue;
          }
          dp[i][j]= min(dp[i][j-ball[i]]+ cost[i], dp[i-1][j]);
        }
    }
  }
  if(dp[n-1][amount]==-1){
    cout<< "That's unfortunate :(" << '\n';
    return 0;
  }
  cout<< "We'll need at least $" << dp[n-1][amount] << '\n';
    return 0;
}
