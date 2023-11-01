#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj[100005];

int main(){

  //ifstream cin("MessageRoutei.txt");
  //ofstream cout("MessageRouteo.txt");
  int n,m;
  cin>> n >> m;
  for(int i=0; i<m; i++){
    int a,b;
    cin>> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int path[n+1];
  int dist[n+1];
  for(int i=0; i<n+1; i++){
    dist[i]=0;
  }

  queue<int> q;

  q.push(1);
  while(!q.empty()){
    int num= q.front();
    q.pop();
    for(auto u : adj[num]){
      if(dist[u]!=0) continue;
      dist[u]=1+dist[num];
      path[u]=num;
      q.push(u);
    }
  }
  if(dist[n]==0){
    cout<< "IMPOSSIBLE";
    return 0;
  }
  cout<< dist[n]+1 << '\n';
  vector<int> v;
  int curr = n;
  for(int i =0; i<dist[n]+1; i++){
    v.push_back(curr);
    curr= path[curr];
  }

  reverse(v.begin(),v.end());
  for(auto u : v){
    cout<< u << " ";
  }
  return 0;
}
