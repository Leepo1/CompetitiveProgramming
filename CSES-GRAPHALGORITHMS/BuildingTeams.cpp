#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

queue<int> q;
bool visited[100005];
bool group[100005];
vector<int> adj[100005];
bool possible=true;

void dfs(int node, bool prev){
  vector<int> v;

  for(auto u: adj[node]){
    if(visited[u]){
      if(group[u]==!prev){
        possible=false;
        break;
      }
    }else{
      v.push_back(u);
    }
  }
  visited[node]=true;
  group[node]=!prev;
  for(auto u: v){
    dfs(u,group[node]);
  }
}

int main(){

  //ifstream cin("BuildingTeamsi.txt");
  //ofstream cout("BuildingTeamso.txt");

  int n,m;

  cin>> n >> m;

  for(int i=0; i<m; i++){
    int a,b;
    cin>> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i=1; i<=n; i++){
    if(visited[i]) continue;
    visited[i]=true;
    group[i]=true;
    dfs(i, true);
    if(!possible) break;
  }

  if(!possible){
    cout<< "IMPOSSIBLE" << '\n';
    return 0;
  }

  for(int i=1; i<=n; i++){
    if(group[i]){
      cout<< 1 << " ";
    }else{
      cout << 2 << " ";
    }
  }
  return 0;
}
