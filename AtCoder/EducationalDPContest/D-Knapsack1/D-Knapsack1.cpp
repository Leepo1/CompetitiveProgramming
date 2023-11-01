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
  //ifstream cin("D-Knapsack1i.txt");
    ll n, capacity;
    cin >> n >> capacity;

    ll weights[n];
    ll values[n];
    for(int i=0; i<n; i++){
      cin >> weights[i] >> values[i];
    }

    ll dp[n][capacity+5];


    for(int i=0; i<n; i++){
      for(int j=0; j<=capacity; j++){
        if(weights[i]>j){
            if(i==0){
              dp[i][j]=0;
            }else {
              dp[i][j]=dp[i-1][j];
            }
        }else {
          if(i==0){
            dp[i][j]=values[i];
          }else {
            dp[i][j]= max(dp[i-1][j], dp[i-1][j-weights[i]] + values[i]);
          }
        }
      }
    }

    cout<< dp[n-1][capacity];




    return 0;
}
