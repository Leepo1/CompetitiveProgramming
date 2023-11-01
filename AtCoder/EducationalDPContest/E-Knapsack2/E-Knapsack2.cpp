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


int main(){

  //ifstream cin("E-Knapsack2i.txt");

  ll n, w;

  cin>> n >> w;

  ll weight[n],value[n];
  ll weightcount=0;
  ll valuecount=0;
  for(int i=0; i<n; i++){
    cin>> weight[i] >> value[i];
    weightcount+=weight[i];
    valuecount+=value[i];
  }
  if(w>=weightcount){
    cout<< valuecount;
    return 0;
  }

  ll dp[n][w+5];


  for(int i=0; i<n; i++){
    for(int j=0; j<=w; j++){
      if(weight[i]>j){
          if(i==0){
            dp[i][j]=0;
          }else {
            dp[i][j]=dp[i-1][j];
          }
      }else {
        if(i==0){
          dp[i][j]=value[i];
        }else {
          dp[i][j]= max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
        }
      }
    }
  }

  cout<< dp[n-1][w];

    return 0;
}
