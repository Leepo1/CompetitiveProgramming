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
vector<ii> starts;
vector<int> answers;
map<ii,int> m;
bool visited[1000][1000];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("Day12i.txt");
  ofstream cout("Day12o.txt");
  string s;
  while(cin>> s){
    grid.push_back(s);
  }
  ii start;
  ii reach;
  int xs,ys;
  xs= grid.size();
  ys= grid[0].size();
  for(int i=0; i<grid.size(); i++){
    for(int j=0; j<grid[i].size(); j++){
      ii temp;
      temp.first=i;
      temp.second=j;
      if(grid[i][j]=='S' || grid[i][j]=='a'){
        starts.push_back(temp);
        m[temp]=1;
        continue;
      }else if(grid[i][j]=='E'){
        reach = temp;
        m[temp]=26;
        continue;
      }
      m[temp]= grid[i][j]-'a'+1;
    }
  }
  for(int g=0; g<starts.size(); g++){
    for(int i=0; i<1000; i++){
      for(int j=0; j<1000; j++){
        visited[i][j]=false;
      }
    }

    int si = starts[g].first*ys + startsk[g].second;
    int final = reach.first*ys+reach.second;
    queue<ii> q;
    q.push({si,0});
    while(!q.empty()){
      ii in = q.front();
      if(in.first==final){
        answers.push_back(in.second);
        break;
      }
      int temp = in.first;
      q.pop();
      int x,y;
      ii old;
      x = temp/ys;
      y = temp%ys;
      old.first=x;
      old.second=y;
      if(visited[x][y]) continue;
      visited[x][y]=true;

      for(int d=0; d<4; d++){
        int nx = x + dx[d];
        int ny = y + dy[d];
        ii t;
        t.first = nx;
        t.second = ny;
        if(nx>=0 && ny>=0 && nx<xs && ny<ys){
          if(visited[nx][ny]) continue;
          if(m[t]-m[old]>1) continue;
          int n = nx*ys + ny;
          q.push({n,in.second+1});
        }
      }

    }
  }
  sort(answers.begin(),answers.end());
  cout<< answers[0] << '\n';

    return 0;
}
