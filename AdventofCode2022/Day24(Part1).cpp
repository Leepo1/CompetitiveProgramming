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

int dx[5] = {1,0,-1,0,0};
int dy[5] = {0,1,0,-1,0};

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("Day24i.txt");
  //ofstream cout("Day24o.txt");
  string s;
  vector<string> grid;

  while(getline(cin,s)){
    grid.push_back(s);
  }

  ii start; start.first = 0; start.second=1;
  int rl = grid[0].size();
  int cl = grid.size();
  ii end; end.first=cl-1; end.second=rl-2;

  int last = end.first*rl + end.second;
  vector<int> horizontal[cl][rl];
  vector<int> vertical[cl][rl];

  for(int i=0; i<cl; i++){
    for(int j=0; j<rl; j++){
      int dir=-1;
      if(grid[i][j]=='^'){
        vertical[i][j].push_back(0);
        dir=2;
      }else if(grid[i][j]=='v'){
        vertical[i][j].push_back(0);
        dir=0;
      }else if(grid[i][j]=='<'){
        horizontal[i][j].push_back(0);
        dir=3;
      }else if(grid[i][j]=='>'){
        horizontal[i][j].push_back(0);
        dir=1;
      }

      if(dir==1 || dir==3){
        int nextspot=j;
        for(int g=1; g<rl-2; g++){
          nextspot+= dy[dir];
          if(grid[i][nextspot]=='#'){
            if(dir==1) nextspot=1;
            if(dir==3) nextspot=rl-2;
          }
          horizontal[i][nextspot].push_back(g);
        }
      }
      if(dir==0 || dir==2){
        int nextspot=i;
        for(int g=1; g<cl-2; g++){
          nextspot+=dx[dir];
          if(grid[nextspot][j]=='#'){
            if(dir==0) nextspot=1;
            if(dir==2) nextspot=cl-2;
          }
          vertical[nextspot][j].push_back(g);
        }
      }

    }
  }
  int time=0;
  queue<ii> q;
  set<int> times[cl][rl];
  int begin = start.first*rl+start.second;
  q.push({0,begin});
  while(!q.empty()){

    ii temp = q.front();
    q.pop();
    int x = temp.second/rl;
    int y = temp.second%rl;
    if(temp.second==last){
      time=temp.first;
      break;
    }
    for(int d=0; d<5; d++){
      int nx = x + dx[d];
      int ny = y + dy[d];
      if(nx>=0 && ny>=0 && nx<cl && ny<rl){
        if(grid[nx][ny]=='#') continue;
        //check if blizzard on that spot
        bool cont=false;
        for(auto u : horizontal[nx][ny]){
          if((temp.first+1)%(rl-2)==u){
            cont=true;
            break;
          }
        }
        if(cont) continue;
        for(auto u : vertical[nx][ny]){
          if((temp.first+1)%(cl-2)==u){
            cont=true;
            break;
          }
        }
        if(cont) continue;
        // otherwise
        int next = nx*rl + ny;
        if(times[nx][ny].find(temp.first+1)==times[nx][ny].end()){
          q.push({temp.first+1,next});
          times[nx][ny].insert(temp.first+1);
        }
      }
    }
  }
  for(int i=0; i<cl; i++){
    for(int j=0; j<rl; j++){
      times[i][j].clear();
    }
  }
  while(!q.empty()) q.pop();
  q.push({time,last});
  while(!q.empty()){
    ii temp = q.front();
    q.pop();
    int x = temp.second/rl;
    int y = temp.second%rl;
    if(temp.second==1){
      time=temp.first;
      break;
    }
    for(int d=0; d<5; d++){
      int nx = x + dx[d];
      int ny = y + dy[d];
      if(nx>=0 && ny>=0 && nx<cl && ny<rl){
        if(grid[nx][ny]=='#') continue;
        //check if blizzard on that spot
        bool cont=false;
        for(auto u : horizontal[nx][ny]){
          if((temp.first+1)%(rl-2)==u){
            cont=true;
            break;
          }
        }
        if(cont) continue;
        for(auto u : vertical[nx][ny]){
          if((temp.first+1)%(cl-2)==u){
            cont=true;
            break;
          }
        }
        if(cont) continue;
        // otherwise
        int next = nx*rl + ny;
        if(times[nx][ny].find(temp.first+1)==times[nx][ny].end()){
          q.push({temp.first+1,next});
          times[nx][ny].insert(temp.first+1);
        }
      }
    }
  }

  for(int i=0; i<cl; i++){
    for(int j=0; j<rl; j++){
      times[i][j].clear();
    }
  }
  while(!q.empty()) q.pop();
  q.push({time,1});
  while(!q.empty()){

    ii temp = q.front();
    q.pop();
    int x = temp.second/rl;
    int y = temp.second%rl;
    if(temp.second==last){
      time=temp.first;
      break;
    }
    for(int d=0; d<5; d++){
      int nx = x + dx[d];
      int ny = y + dy[d];
      if(nx>=0 && ny>=0 && nx<cl && ny<rl){
        if(grid[nx][ny]=='#') continue;
        //check if blizzard on that spot
        bool cont=false;
        for(auto u : horizontal[nx][ny]){
          if((temp.first+1)%(rl-2)==u){
            cont=true;
            break;
          }
        }
        if(cont) continue;
        for(auto u : vertical[nx][ny]){
          if((temp.first+1)%(cl-2)==u){
            cont=true;
            break;
          }
        }
        if(cont) continue;
        // otherwise
        int next = nx*rl + ny;
        if(times[nx][ny].find(temp.first+1)==times[nx][ny].end()){
          q.push({temp.first+1,next});
          times[nx][ny].insert(temp.first+1);
        }
      }
    }
  }
  cout<< time << '\n';
    return 0;
}
