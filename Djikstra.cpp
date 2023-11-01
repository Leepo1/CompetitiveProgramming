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
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,int> pii;
typedef long long ll;

priority_queue< ii, vector<ii>, greater<ii> > pq;
vector<ii> adj[10005];
int dist[10005];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  //ifstream cin("routesi.txt");
  //ofstream cout("routeso.txt");
  int t; cin>> t;
  while(t--){
    for(int i=0; i<10005; i++){
      dist[i]=-1;
      adj[i].clear();
    }
    int n,c; cin>> n >> c;

    for(int i=0; i<c; i++){
      int f,s,d; cin>> f >> s >>d;
      adj[f].push_back({d,s});
      adj[s].push_back({d,f});
    }

    for(auto u : adj[1]){
      pq.push(u);
    }
    dist[1]=0;

    while(!pq.empty()){
      ii temp = pq.top();
      pq.pop();
      if(dist[temp.second]!=-1) continue;
      dist[temp.second]=temp.first;

      for(auto u : adj[temp.second]){
        if(dist[u.second]!=-1) continue;
        pq.push({temp.first+u.first,u.second});
      }
    }
  }

    return 0;
}
