#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <set>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

vector<int> adj[10005];
bool visited[10005];
int n;
int change=0;
bool atleast=false;
bool bad=false;
int comp=0;
int edgecount=0;
int nodecount=0;

void dfs(int u){
  visited[u]=true;
  nodecount++;
  for(auto b : adj[u]){
    atleast=true;
    edgecount++;
    if(visited[b]){
      continue;
    }
    dfs(b);
  }
}

void cc(){
  for(int i=1; i<=n; i++){
    if(!visited[i]){
      atleast=false;
      nodecount=0;
      edgecount=0;
      dfs(i);
      edgecount= edgecount/2;
      //cout<< edgecount << " " << nodecount << endl;
      if(edgecount>nodecount-1){
        change++;
      }
      if(atleast){
        comp++;
      }

    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  //ifstream cin("starsi.txt");
  //ofstream cout("starso.txt");
  int t;
  cin>> t;
  while(t--){
    for(int i=0; i<10005; i++){
      adj[i].clear();
      visited[i]=false;
    }
    change=0;
    comp=0;

    int c;
    cin>> n >> c;
    for(int i=0; i<c; i++){
      int a,b;
      cin>> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    cc();
    cout<< comp << " " << change << '\n';
  }

    return 0;
}
