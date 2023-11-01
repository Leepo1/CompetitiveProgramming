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
  //ifstream cin("blocki.txt");
  //ofstream cout("blocko.txt");
  int c;
  cin>> c;
  while(c--){
    int r,c,b;
    cin>> r >> c>> b;

    char grid[r][c];

    int dist[r][c];
    int startx,starty,endx,endy;
    cin>> startx >> starty >>endx >> endy;
    int xblock[b];
    int yblock[b];

    for(int i=0; i<b; i++){
      cin>> xblock[i] >> yblock[i];
      grid[xblock[i]][yblock[i]]='#';
    }

    for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
        dist[i][j]=-1;
      }
    }

    queue<int> q;
    q.push(startx*c+starty);
    dist[startx][starty]=0;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        int x = node/c;
        int y= node%c;
          for(int i=0; i<4; i++){
            int nx= x + dx[i];
            int ny= y + dy[i];
            if(nx>=0 && nx<r && ny>=0 && ny<c && grid[nx][ny]!='#'){
              if(dist[nx][ny]!=-1) continue;
              dist[nx][ny]=dist[x][y]+1;
              q.push(nx*c+ny);
            }
          }

    }
    if(dist[endx][endy]==-1){
      cout<< ":(" << '\n';
    }else{
      cout<< dist[endx][endy] <<'\n';
    }

  }
  return 0;
}
