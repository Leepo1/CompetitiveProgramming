#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
vector<string> grid;
vector<int> answers;
bool visited[1000][1000];
int dx[4]= {1,-1,0,0};
int dy[4]= {0,0,1,-1};
map<ii,int> m;
int answer=100000;
void floodfill(int x, int y, int distance){
  visited[x][y]=true;
  ii old;
  old.first=x;
  old.second=y;
  if(grid[x][y]=='E'){
    answer = min(answer,distance);
    return;
  }

  for(int d=0; d<4; d++){
    int nx = x +dx[d];
    int ny = y +dy[d];
    ii t;
    t.first=nx;
    t.second=ny;
    if(nx>=0 && ny>=0 && nx<41 && ny<65){
      if(visited[nx][ny]) continue;
      if(m[t]-m[old]>1) continue;
      floodfill(nx,ny,distance+1);
      visited[nx][ny]=false;
    }

  }

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("Day12i.txt");
  ofstream cout("Day12o.txt");
  string s;
  while(cin>> s){
    grid.push_back(s);
  }
  int sx,sy;
  for(int i=0; i<grid.size(); i++){
    for(int j=0; j<grid[i].size(); j++){
      ii temp;
      temp.first=i;
      temp.second=j;

      if(grid[i][j]=='S'){
        sx=i,sy=j;
        m[temp]=1;
        continue;
      }else if(grid[i][j]=='E'){
        m[temp]=26;
        continue;
      }
      m[temp]= grid[i][j]-'a'+1;
    }
    cout<< '\n';
  }
  floodfill(sx,sy,0);
  sort(answers.begin(),answers.end());
  //for(auto u : answers) cout<< u << '\n';
  cout<< answer << '\n';
    return 0;
}
