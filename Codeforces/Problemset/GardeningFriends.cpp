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
#include <ility>
#define INF 2000000000
using namespace std;
#define pii pair<int, pair<int,int>>
#define pi pair<int,int>


vector<int> adj[1000005];

int main (){    
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  //ifstream cin ("usaco.in")
  //ofstream co ("usaco.out")
  int t; cin>> t;
  while(t--){
    for(int i=0; i<1000005; i++) adj[i].clear();
    int n,k,c; cin>> n >> k >> c;
       for(int i=0; i<n-1; i++){
      int a,b; cin>> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    //BFS from root
    queue<pi> q;
    q.push(make_pair(0,1));
    int droot[n+5];
    pi furthest; furthest.first=0;
    for(int i=0; i<n+5; i++) droot[i]=-1;
    droot[1]=0;
    while(!q.empty()){
      pi temp = q.front();
      q.pop();
      for(auto u : adj[temp.second]){
        if(droot[u]!=-1) continue;
        droot[u] = temp.first+1;
        if(droot[u]>furthest.first) furthest.first = droot[u]; furthest.second=u;
        q.push(make_pair(droot[u],u));
      }
    }
   if(c>=k){
      cout<< furthest.first*k << '\n';
      continue;

   }     // From furthest point 
    int dfmax[n+5];
    q.push(make_pair(0,furthest.second));
    pi sfurthest; sfurthest.first=0;
    for(int i=0; i<n+5; i++) dfmax[i]=-1;
    dfmax[furthest.second]=0;
    while(!q.empty()){
      pi temp = q.front();
      q.pop();
      for(auto u : adj[temp.second]){
        if(dfmax[u]!=-1) continue;
        dfmax[u] = temp.first+1;
        if(dfmax[u]>sfurthest.first) sfurthest.first = dfmax[u]; sfurthest.second=u;
        q.push(make_pair(dfmax[u],u));
      }
    }
    int answer = 0;
    for(int i=1; i<=n; i++){
      answer = max(answer,dfmax[i]*k-droot[i]*c);
    }  
    cout<< answer << '\n';
  }




//cout<<'\n';
return 0;

}
