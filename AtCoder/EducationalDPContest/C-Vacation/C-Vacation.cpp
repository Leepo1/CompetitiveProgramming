#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){
  //ifstream cin("C-Vacationi.txt");
  //ofstream cout("C-Vacationo.txt");
  int n;
  cin >> n;
  int cost[n][3];
  for(int i=0; i<n; i++){
    cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
  }
  int dp[n][3];

  for(int i=1; i<n; i++){
    for(int j=0; j<3; j++){
      dp[i][j] = 0;
    }
  }

  dp[0][0]=cost[0][0];
  dp[0][1] =cost[0][1];
  dp[0][2] =cost[0][2];



  for(int i=1; i<n; i++){
    for(int j=0; j<3; j++){
      dp[i][j] = cost[i][j] + max(dp[i-1][(j+2)%3], dp[i-1][(j+1)%3]);
    }
  }

  int answer = max(dp[n-1][0],dp[n-1][1]);
  answer = max(answer, dp[n-1][2]);
  cout << answer;
  return 0;
}
