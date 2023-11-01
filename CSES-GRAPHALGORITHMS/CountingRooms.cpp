#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
int n,m;
char grid[1005][1005];
bool visited[1005][1005];
int dx[4]= {1,-1,0,0};
int dy[4]= {0,0,1,-1};
void floodfill(int x, int y){
  visited[x][y]=true;
  for(int d=0; d<4; d++){
    int nx= x+dx[d];
    int ny= y+dy[d];
    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]!='#'){
      if(visited[nx][ny]) continue;
      floodfill(nx,ny);
    }
  }
}
int main(){

  //ifstream cin("CountingRoomsi.txt");
  //ofstream cout("CountingRoomso.txt");

  int rooms=0;
  cin>> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin>> grid[i][j];
    }
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(grid[i][j]=='#' || visited[i][j]) continue;
      rooms++;
      floodfill(i,j);
    }
  }
  cout<< rooms << '\n';
  return 0;
}
