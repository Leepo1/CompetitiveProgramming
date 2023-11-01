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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  //ifstream cin("rooki.txt");
  //ofstream cout("rooko.txt");
  int c;
  cin>> c;
  while(c--){
    int n;
    cin>> n;
    long long arr[n][n];
    long long row[n];
    long long col[n];
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        cin>> arr[i][j];
      }
    }
    for(int i=0; i<n; i++){
      long long currsum=0;
      for(int j=0; j<n; j++){
        currsum+=arr[i][j];
      }
      row[i]=currsum;
    }

    for(int i=0; i<n; i++){
      long long currsum=0;
      for(int j=0; j<n; j++){
        currsum+=arr[j][i];
      }
      col[i]=currsum;
    }

    long long answer;

    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(i==0 && j==0){
          long long score= col[j]+row[i]-2*arr[i][j];
          answer=score;
        }else{
          long long score= col[j]+row[i]-2*arr[i][j];
          answer=max(score,answer);
        }
      }
    }
    cout<< answer << '\n';
  }
    return 0;
}
