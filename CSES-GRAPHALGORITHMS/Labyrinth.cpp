#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;

int dx[4]= {1,-1,0,0};
int dy[4]= {0,0,1,-1};

char grid[1005][1005];
int dist[1000005];
char path[1000005];
int main(){

  //ifstream cin("Labyrinthi.txt");
  //ofstream cout("Labyrintho.txt");

  int n,m;
  cin>> n >> m;
  for(int i=0; i<1000005; i++){
    dist[i]=-1;
  }

  int startx;
  int starty;
  int endx;
  int endy;

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin>> grid[i][j];

      if(grid[i][j]=='A'){
        startx=i;
        starty=j;
      }

      if(grid[i][j]=='B'){
        endx=i;
        endy=j;
      }

    }
  }

  bool found=false;
  queue<int> q;
  dist[startx*m+starty]=0;
  q.push(startx*m+starty);

  while(!q.empty()){
    int temp= q.front();
    q.pop();
    int currx= temp/m;
    int curry= temp%m;

    for(int d=0; d<4; d++){
      int nx= currx+ dx[d];
      int ny= curry+ dy[d];

      int number= nx*m + ny;
      if(nx>=0 && ny>=0 && nx<n && ny<m){
        if(grid[nx][ny]=='#') continue;
        if(dist[number]!=-1) continue;
          dist[number]= dist[temp]+1;
          if(d==0){
            path[number]='D';
          }else if(d==1){
            path[number]='U';
          }else if(d==2){
            path[number]='R';
          }else if(d==3){
            path[number]='L';
          }
          if(nx==endx && ny==endy){
            found=true;
            break;
          }
          q.push(number);
      }

    }
    if(found) break;

  }

  if(dist[endx*m+endy]==-1){
    cout<< "NO" << '\n';
    return 0;
  }

  cout<< "YES" << '\n';
  cout << dist[endx*m+endy] << '\n';

  int currspotx= endx;
  int currspoty= endy;
  string answer="";

  for(int i=0; i<dist[endx*m+endy]; i++){
    int spot= currspotx*m+currspoty;
    answer+=path[spot];
    int dir;
    if(path[spot]=='D'){
      dir=0;
    }else if(path[spot]=='U'){
      dir=1;
    }else if(path[spot]=='R'){
      dir=2;
    }else if(path[spot]=='L'){
      dir=3;
    }
    currspotx-=dx[dir];
    currspoty-=dy[dir];
  }
  reverse(answer.begin(),answer.end());
  cout<< answer << '\n';

  return 0;
}
