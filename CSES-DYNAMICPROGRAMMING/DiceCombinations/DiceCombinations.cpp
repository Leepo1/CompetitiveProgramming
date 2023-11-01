#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

long long dp[1000005];
int main(){

  dp[1]=1;
  //ifstream cin("DiceCombinationsi.txt");

  int n;
  cin>> n;
  for(int i=2; i<=n; i++){
    if(i<7){
      dp[i]++;
    }
    for(int k=1; k<=6; k++){

      if(i-k>=1){
        dp[i]= (dp[i]+ dp[i-k])%(1000000000+7);
      }

    }
  }

  cout<< dp[n];





  return 0;
}
