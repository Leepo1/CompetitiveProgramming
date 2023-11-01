#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int dx[2]= {1,0};
int dy[2]= {0,1};

int main(){


  //ifstream cin("GridPathsi.txt");
  int n;
  cin>> n;

  string grid[n];

  string temp;

  getline(cin,temp);

  for(int i=0; i<n; i++){
    cin>> grid[i];
  }

  int dp[n][n];


    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        dp[i][j]=0;
      }
    }

      dp[0][0]=1;
  if(grid[n-1][n-1]=='*'){
    cout<< 0;
    return 0;
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        if(grid[i][j]=='*'){
          continue;
        }
      for(int d=0; d<2; d++){

        int nx= i + dx[d];
        int ny= j + dy[d];

        if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]!='*'){
          dp[nx][ny]= (dp[nx][ny]+ dp[i][j]) % (1000000000+7);
        }

      }

    }
  }

  cout<< dp[n-1][n-1];
  return 0;
}
