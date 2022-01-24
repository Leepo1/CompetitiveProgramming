#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <stdlib.h>
#include <utility>
#include <stack>
using namespace std;
int dx[]={1,-1,0,0,1,1,-1,-1};
int dy[]={0,0,1,-1,1,-1,1,-1};
int answer=0;
int arr[10][10];
void flash(int a, int b){
  answer+=1;
arr[a][b]=0;
for(int i=0; i<8; i++){
  if(arr[a+dx[i]][b+dy[i]]!=0 && 0<=a+dx[i] && a+dx[i]<=9 && 0<=b+dy[i] && b+dy[i]<=9){
    arr[a+dx[i]][b+dy[i]]+=1;
    if(arr[a+dx[i]][b+dy[i]]>=10){
      flash(a+dx[i],b+dy[i]);
    }
  }

}

}

int main(){
  char c;

  ifstream cin("AdventofCodeDay11.in");
  ofstream cout("AdventofCodeDay11.out");
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      cin>> c;
      arr[i][j]= c-'0';
    }
  }
  int t=0;
  while(true){
t=t+1;
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
     arr[i][j]+=1;
    }
  }
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
     if(arr[i][j]==10){
       flash(i,j);
     }
    }
  }
  bool a=true;
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
     if(arr[i][j]==0){
       continue;
     }else {
       a=false;
     }
    }
  }
  if(a){
    cout<<t;
    break;
  }
  }
      return 0;
}
