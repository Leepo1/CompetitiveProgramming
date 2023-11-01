#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

priority_queue< ii, vector<ii>, greater<ii>> pq;
bool visited[105];
vector<ii> adj[105];
int main() {


//ifstream cin("anti.txt");
//ofstream cout("anto.txt");
  int c;
  cin >> c;
  int campus=1;
  while(c--){
    for(int i=0; i<105; i++){
      visited[i]=false;
      adj[i].clear();
    }
    while(!pq.empty()){
      pq.pop();
    }
    int n;
    cin>> n;
    int connect;
    cin>> connect;
    for(int i=0; i<connect; i++){
      int fir, sec, dist;
      cin>> fir >> sec >> dist;
      adj[fir].push_back({dist,sec});
      adj[sec].push_back({dist,fir});
    }
    for(auto u : adj[1]){
      pq.push(u);
    }
    visited[1]=true;
    int ne=0;
    int cost=0;
    while(!pq.empty()){
      ii temp = pq.top();
      pq.pop();
      if(visited[temp.second]){
        continue;
      }
      visited[temp.second]=true;
      ne++;
      cost+= temp.first;
      if(ne==n-1) break;
      for(auto u : adj[temp.second]){
        if(visited[u.second]) continue;
        pq.push(u);
      }

    }
    cout<< "Campus #" << campus << ": ";
    if(ne!=n-1){
      cout<< "I'm a programmer, not a miracle worker!" << '\n';
    }else{
      cout<< cost << '\n';
    }
    campus++;
  }
  return 0;
}
