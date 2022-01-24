#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
using namespace std;
int arr[100000][100000];
int main(){
  ifstream cin("AdventofCodeDay5.in");
  ofstream cout("AdventofCodeDay5.out");
int x,y,x1,y1;
string s;
char c;
int count=0;
for(int q=1; q<501; q++){
cin>> x;
cin>>c;
cin>>y;
cin>>s;
cin>>x1;
cin>>c;
cin>>y1;
if((x1-x)==(y1-y) || (x-x1)==(y1-y)){
map<int,int> m;
m[x]=y;
m[x1]=y1;
int a=min(x,x1);
int b=max(x,x1);
int c=b-a;
if((y1-y)/(x1-x)==1){
for(int i=0; i<=c; i++){
  arr[a+i][m[a]+i]=arr[a+i][m[a]+i]+1;
}
}else{
  for(int i=0; i<=c; i++){
    arr[a+i][m[a]-i]=arr[a+i][m[a]-i]+1;
  }
}
}
else if(x==x1){
  int a=min(y,y1);
  int b=max(y,y1);
  for(int i=a; i<=b; i++){
  arr[x][i]=arr[x][i]+1;
}
}
else if(y==y1) {
  int a=min(x,x1);
  int b=max(x,x1);
  for(int i=a; i<=b; i++){
  arr[i][y]=arr[i][y]+1;
}
}
}
for(int i=0; i<10000; i++){
  for(int j=0; j<10000; j++){
    if(arr[i][j]>1){
      count=count+1;
    }
  }
}
cout<< count;
    return 0;
}
