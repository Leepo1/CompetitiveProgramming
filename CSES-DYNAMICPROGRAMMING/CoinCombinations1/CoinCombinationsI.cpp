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


  //ifstream cin("CoinCombinations1i.txt");

  int n, x;
  cin>> n >> x;
  int arr[n];
  int dp[1000005];

  for(int i=0; i<=x; i++){
    dp[i]=0;
  }

  for(int i=0; i<n; i++){
    cin>> arr[i];
    dp[arr[i]]=1;
  }


  for(int i=1; i<=x; i++){
    for(int k=0; k<n; k++){
      if(i-arr[k]>0){
        dp[i]= (dp[i] + dp[i-arr[k]])%(1000000000+7);
      }
    }
  }
  cout<< dp[x];




  return 0;
}
