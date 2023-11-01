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

  //ifstream cin("MinimizingCoinsi.txt");

  int n, x;
  cin>> n >> x;
  int arr[n];
  int dp[x+5];

  for(int i=0; i<=x; i++){
    dp[i]=0;
  }

  for(int i=0; i<n; i++){
    cin>> arr[i];
    dp[arr[i]]=1;
  }


  for(int i=1; i<=x; i++){
    for(int k=0; k<n; k++){
      if(i-arr[k]>0 && dp[i-arr[k]]!=0){
        if(dp[i]==0){
          dp[i]= dp[i-arr[k]]+1;
        }else {
          dp[i]= min(dp[i], dp[i-arr[k]]+1);
        }
      }
    }
  }

  if(dp[x]==0){
    cout<< -1;
  }else {
    cout<< dp[x];
  }



  return 0;
}
