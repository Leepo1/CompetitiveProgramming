#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

bool visited[100005];
vector<int> connect;
vector<int> adj[100005];
void dfs(int node){
  visited[node]=true;
  for(auto u: adj[node]){
    if(!visited[u]) dfs(u);
  }
}
int currparent=1;
int numbcomp=1;
void cc(int size){
  for(int i=2; i<=size; i++){
    if(!visited[i]){
      connect.push_back(i);
      dfs(i);
      numbcomp++;
    }
  }
}
int main(){

  //ifstream cin("BuildingRoadsi.txt");
  //ofstream cout("BuildingRoadso.txt");

  int n,c;
  cin>> n >> c;

  for(int i=0; i<c; i++){
    int a,b;
    cin>> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1);
  cc(n);
  cout<< numbcomp-1 << '\n';
  for(auto u: connect){
    cout<< 1 << " " << u << '\n';
  }
  return 0;
}
