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
using namespace std;
bool visited[200005];
int distance[200006];
vector<int> adj[200005];
typedef pair<int,int> ii;
typedef long long ll;

int cmd=0;
int mn=1;

void dfs(int distance, int node){
  if(distance>cmd){
    cmd=distance;
    mn=node;
  }
  visited[node]=true;
  for(auto u: adj[node]){
    if(visited[u]) continue;
    dfs(distance+1,u);
  }
}

int main(){
  ifstream cin("TreeDiameteri.txt");
  ofstream cout("TreeDiametero.txt");
    int n;
    cin>> n;
    vector<int> adj[n];

    for(int i=0; i<n; i++){
        int a,b;
        cin>> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0,1);
    dfs(0,mn);

    /*
    BFS way
    queue<ii> q;
    int dist=0;
    q.push({0,1});


    while(!q.empty()){
        ii temp = q.front();
        dist[]
        q.pop();
        visited[temp.second]=true
        for(auto v : adj[temp.second]){
            if(!visited[v.second]){
                q.push({v.first+1,v.second});
            }
        }
    }
    */

    return 0;
}
