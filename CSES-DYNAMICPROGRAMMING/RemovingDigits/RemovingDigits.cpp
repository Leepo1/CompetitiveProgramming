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

  //ifstream cin("RemovingDigitsi.txt");
  int x;
  cin>> x;
  int dp[x+5];
  dp[0]=0;
  for(int i=1; i<=x; i++){
    dp[i]=1e9;
  }
  for(int i=1; i<=x; i++){
    string s= to_string(i);
    for(char c : s){
      dp[i]=min(dp[i],dp[i-(c-'0')]+1);
    }
  }

  cout<< dp[x];


  return 0;
}
