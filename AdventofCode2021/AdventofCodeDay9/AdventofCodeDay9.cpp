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
using namespace std;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int arr[100][100];
bool brr[105][105];

int func(int a, int b){
  int count=1;
  if(brr[a][b]){
    return 1;
  }
  brr[a][b]=true;
  for(int i=0; i<4; i++){
    int nx=dx[i]+a;
    int ny=dy[i]+b;
    if(nx>=100 || ny>=100 || nx<0|| ny<0){
      continue;
    }
    if(brr[nx][ny] || arr[nx][ny]<arr[a][b] || arr[nx][ny]==9){
      continue;
    }
      count=count+func(nx,ny);

  }
  return count;

}

int main(){
  vector<int> v;
  ifstream cin("AdventofCodeDay9.in");
  ofstream cout("AdventofCodeDay9.out");

  string s;
  long long sum=0;
  for(int i=0; i<100; i++){
    cin>> s;
    for(int j=0; j<100; j++){
      arr[i][j]= s[j] -'0';
    }
  }


for(int i=0; i<100; i++){
  for(int j=0; j<100; j++){
    if((arr[i][j]<arr[i-1][j] || i==0) && (arr[i][j]<arr[i][j-1] || j==0) && (arr[i][j]<=arr[i+1][j] || i==99) && (arr[i][j]<arr[i][j+1] || j==99)) {
      v.push_back(func(i,j));
    }
    }
  }
int vsize=v.size();
sort(v.begin(),v.end());
  cout<< v[vsize-1]*v[vsize-2]*v[vsize-3];
return 0;
}
