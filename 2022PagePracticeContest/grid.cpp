#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int main(){
  //ifstream cin("gridi.txt");
  //ofstream cout("grido.txt");
  int r,c;
  cin>> r >> c;

  char grid[r][c];

  int dist[r][c];
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      cin>> grid[i][j];
      dist[i][j]=-1;
    }
  }

  queue<int> q;
  q.push(0);
  dist[0][0]=0;

  while(!q.empty()){
      int node = q.front();
      q.pop();
      int x = node/c;
      int y= node%c;
      int move= grid[x][y] - '0';
        for(int i=0; i<4; i++){
          int nx= x + move*dx[i];
          int ny= y + move*dy[i];
          if(nx>=0 && nx<r && ny>=0 && ny<c){
            if(dist[nx][ny]!=-1) continue;
            dist[nx][ny]=dist[x][y]+1;
            q.push(nx*c+ny);
          }
        }

  }
  cout<< dist[r-1][c-1] <<'\n';
  return 0;
}
