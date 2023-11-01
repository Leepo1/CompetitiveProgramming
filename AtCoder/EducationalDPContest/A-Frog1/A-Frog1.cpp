#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int main(){
  ifstream cin("A-Frog1.txt");
  ofstream cout("A-Frog1o.txt");
  int n;
  cin>> n;
  int arr[n];
  for(int i=0; i<n; i++){
    cin>> arr[i];
  }
  int dp[n];
  dp[0]=0;
  dp[1]=abs(arr[1]-arr[0]);
  for(int i=2; i<n; i++){
    dp[i]= min(dp[i-1]+abs(arr[i]-arr[i-1]), dp[i-2]+abs(arr[i]-arr[i-2]));
  }
  cout<< dp[n-1];
  return 0;
}
