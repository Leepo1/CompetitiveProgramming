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

  //ifstream cin("CoinCombinations2i.txt");

    int n,x;
    
    cin>> n >> x;

    vector<int> coins(n);

    for(int i=0; i<n; i++) cin>> coins[i];

    int MOD= 1e9 +7;

    int dp[x+5];

    dp[0]=1;

    for(int i=1; i<=x; i++) dp[i]=0;

    for(auto coin : coins){
      for(int i=coin; i<=x; i++){
        dp[i]= (dp[i] +dp[i-coin])% MOD;
      }
    }
    cout<< dp[x];



  return 0;
}
