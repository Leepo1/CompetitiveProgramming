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
#include <string.h>
#include <queue>

using namespace std;

priority_queue< pair<int, pair< int,int> >, vector< pair< int, pair<int,int> > >, greater < pair<int, pair<int,int> > > > bestofriendo;
int dx[]= {1,0,-1,0};
int dy[]= {0,-1,0,1};
int arr[500][500];
int dist[500][500] ={[0 ... 499][0 ... 499]=-1};
int main(){
  ifstream cin("AdventofCodeDay15.in");
  ofstream cout("AdventofCodeDay15.out");
  string s;
for(int q=0; q<100; q++){
  cin>> s;

  for(int t=0; t<100; t++){
    arr[q][t]= s[t]-'0';
  }
}
for(int q=0; q<5; q++){
  for(int t=0; t<5; t++){
    for(int a=0; a<100; a++){
      for(int b=0; b<100; b++){
      arr[a+q*100][b+t*100]=(t+q+arr[a][b]-1)%9+1;
      }
    }
  }
}





bestofriendo.push(make_pair(0, make_pair(0,0)));
while(!bestofriendo.empty()){
  pair<int, pair<int,int> > pii=bestofriendo.top();
  bestofriendo.pop();
  if(dist[pii.second.first][pii.second.second]!=-1){
    continue;
  }
  dist[pii.second.first][pii.second.second]=pii.first;
  for(int q=0; q<4; q++){
      int nx= dx[q]+pii.second.first;
      int ny= dy[q]+pii.second.second;

        if(nx<0 || ny<0 || nx>=500 || ny>=500){
          continue;
        }
        if(dist[nx][ny]!=-1){
          continue;
        }
        if(nx==499 && ny==499){
          cout<< pii.first + arr[499][499];
          return 0;
        }


        bestofriendo.push( make_pair(pii.first + arr[nx][ny], make_pair(nx,ny)));
  }
}
    return 0;
  }
