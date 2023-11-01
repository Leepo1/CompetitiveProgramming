/*
ID: Sameer Bhatti 
Grade:8
Task:
LANG: C++11
*/
/* LANG can be C++11 or C++14 for those more recent releases */

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
#define pii pair<int, pair<int,int>>
#define pi pair<int,int>
vector<int> adj[100005];
bool visited[100005];
bool cf=false;
vector<int> v;
void dfs(int node, int prev, vector<int> &v){
  v.push_back(node);
  visited[node]=true;
  for(auto u : adj[node]){
    if(visited[u]){
      if(prev!=u){
        v.push_back(u);
        bool start=false;
        vector<int> f;
        for(auto l: v){
          if(start){
            f.push_back(l);
            continue;
          }    
          if(u==l){
            start=true;
            f.push_back(l);
          }
        }
        cout<< f.size() << '\n';
        for(auto l : f) cout<< l << " ";
        cf=true;
        return;
      }
      continue;
    }
    dfs(u,node,v);
    if(cf) return;
    v.pop_back();
  }
  return;
}
int main (){

//ifstream cin ("usaco.in")
//ofstream cout ("usaco.out")

  int n,m; cin>> n >> m;
  for(int i=0; i<m; i++){
    int a,b; cin>> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int use;
    for(int i=1; i<=n; i++) {
        v.clear();
        if(!visited[i]) dfs(i,0,v);
        if(cf) break;
    }          
      if(!cf) cout<< "IMPOSSIBLE" << '\n';
    

//cout<<'\n';
return 0;

}
