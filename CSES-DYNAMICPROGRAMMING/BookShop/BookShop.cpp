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



  //ifstream cin("BookShopi.txt");
  int n, capacity;
  cin >> n >> capacity;

  int price[n];

  for(int i=0; i<n; i++){
    cin>> price[i];
  }

  int pages[n];

  for(int i=0; i<n; i++){
    cin>> pages[i];
  }

  int knapsack[n+5][capacity+5];

  for(int i=0; i<n; i++){
    for(int j=0; j<=capacity; j++){
      if(price[i]>j){
        if(i==0){
          knapsack[i][j]=0;
        }else{
          knapsack[i][j]=knapsack[i-1][j];
        }

      }else{
        if(i==0){
          knapsack[i][j]=pages[i];
        }else{
          knapsack[i][j]=max(knapsack[i-1][j-price[i]]+pages[i],knapsack[i-1][j]);
        }

      }

    }
  }


  cout<< knapsack[n-1][capacity];
  return 0;
}
