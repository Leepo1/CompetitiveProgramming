/*
ID: Sameer Bhatti 
Grade:8
Task:
LANG: C++11
 LANG can be C++11 or C++14 for those more recent releases */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <utility>
#define INF 2000000000
using namespace std;
#define pii pair<int, pair<int,int> >

#define pi pair<int,int>

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

string cdir(int n){
  if(n==0) return "D";
  if(n==1) return "U";
  if(n==2) return "R";
  if(n==3) return "L"; 
}
int main (){
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
   int n,m; cin>> n >> m;
  char grid[n][m];
  vector<pi> monsters;
  pi start;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin>> grid[i][j];
      if(grid[i][j]=='M') monsters.push_back(make_pair(i,j));
      if(grid[i][j]=='A') {
        start.first=i; start.second=j;
      }
    }
  }
   if(start.first==0 || start.first==n-1 || start.second==0 || start.second==m-1){
     cout<< "YES" << '\n';
     cout << 0 << '\n';
     return 0;
   }
  //BFS from A and determine distances to points
  //Create int grid which tells if you a monster 
  // Can reach a spot at the same time or before you
  
  int l = monsters.size();
  queue<pi> mqs;
  int mdist[n][m];
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      mdist[i][j]=-1;
    }
  }
  queue<pi> q;
  int dist[n][m];
   for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        dist[i][j] = -1;
      }
    }
    for(auto u : monsters){
      mqs.push(u);
      mdist[u.first][u.second]=0;
    }
  int ans=-1;
  pi spot;
  int gt[n][m];

  bool done=false;
  q.push(start);
  dist[start.first][start.second]=0;
  int steps = 0;
while(!done){
    if(q.empty()) break;
    steps++;
   
    while(!mqs.empty() && mdist[mqs.front().first][mqs.front().second] < steps){
      pi temp = mqs.front();
      mqs.pop();
      for(int d=0; d<4; d++){
        int nx = temp.first + dx[d];
        int ny = temp.second + dy[d];
        if(0<=nx && nx<n && 0<=ny && ny<m){
          if(grid[nx][ny]=='#') continue;
          if(mdist[nx][ny]!=-1) continue;
          mdist[nx][ny]=mdist[temp.first][temp.second]+1;
          mqs.push(make_pair(nx,ny));
        }
      }
    }


   while(!q.empty() && dist[q.front().first][q.front().second] < steps){
    pi temp = q.front();
    q.pop();
    if (done) break;
    for(int d=0; d<4; d++){
      int nx = temp.first + dx[d];
      int ny = temp.second + dy[d];
      if(0<=nx && nx<n && 0<=ny && ny<m){
        if(dist[nx][ny]!=-1) continue;
        if(grid[nx][ny]=='#') continue;
        if(mdist[nx][ny]!=-1) continue;
        if(nx==0 || nx==n-1 || ny==0 || ny==m-1){
          ans = dist[temp.first][temp.second]+1;
          spot.first = nx;
          spot.second = ny;
          queue<pi> t;
          gt[nx][ny] = d;
          q = t;
          done=true;
          break;
        }
        gt[nx][ny] = d;
        dist[nx][ny]=dist[temp.first][temp.second]+1;
        q.push(make_pair(nx,ny));
      }
    }
  }

}
    
  if(ans==-1){
  cout  << "NO" << '\n';
    return 0;
  }

  cout << "YES" << '\n';
  cout << ans << '\n';
  string path = "";
  for(int i=0; i<ans; i++){
    int dir = gt[spot.first][spot.second];
    path += cdir(dir);
    spot.first = spot.first + -1*dx[dir];
    spot.second = spot.second + -1*dy[dir];
  }
  reverse(path.begin(),path.end());
  cout << path << '\n';


//<<'\n';
return 0;

}
