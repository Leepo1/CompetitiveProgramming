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
int arr[15][15];
void flip(int x, int y){

  for(int i=0; i<=x; i++){
    for(int j=0; j<=y; j++){
      if(arr[i][j]==1){
        arr[i][j]=0;
      }else{
        arr[i][j]=1;
      }
    }

  }
  return;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  //ifstream cin("cowtip.in");
  //ofstream cout("cowtip.out");
  int count=0;
  int n;
  cin>> n;

  for(int i=0; i<n; i++){
    string s;
    cin>> s;
    for(int j=0; j<n; j++){
      arr[i][j]= s[j]- '0';
    }
  }


  for(int i=n-1; i>=0; i--){
    for(int j=i; j>=0; j--){
      if(i==j){
        if(arr[i][j]==1){
          flip(i,j);
          count++;
        }
        continue;
      }

      if(arr[i][j]==1){
        flip(i,j);
        count++;
      }
      if(arr[j][i]==1){
        flip(j,i);
        count++;
      }


    }
  }

  cout<< count<< '\n';


    return 0;
}
