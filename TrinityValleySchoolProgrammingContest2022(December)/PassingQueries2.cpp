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
#include <sstream>
using namespace std;

typedef pair<int,int> ii;
typedef long long ll;
typedef pair<int,string> is;

int distance(ii p1, ii p2){
  return abs(p1.first-p2.first)+abs(p1.second-p2.second);
}

map<string, vector<is> > adj;
map<string, ii> pos;
map<string, int> range;
map<string,int> mst;


priority_queue< is, vector<is>, greater<is> > pq;


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("PassingQueries2i.txt");
  ofstream cout("PassingQueries2o.txt");

  int N;
  cin>> N;
  //Reading Input into Corresponding Data Structures
  vector<string> names;

  for(int i=0; i<N; i++){
    string name;
    ii temp;
    int tr;
    cin>> name >>  temp.first >> temp.second >> tr;
    pos[name]=temp;
    range[name]=tr;
    names.push_back(name);
  }

  //Constructing Graph
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(j==i) continue;
      int d = distance(pos[names[i]],pos[names[j]]);
      if(d<= range[names[i]]) adj[names[i]].push_back({d,names[j]});
    }
  }

  string start, end; cin>> start >> end;
  for(int i=0; i<N; i++){
    mst[names[i]]=-1;
  }
  mst[start]=0;
  pq.push({0,start});

  while(!pq.empty()){
    is temp = pq.top();
    pq.pop();
    mst[temp.second]=temp.first;
    if(temp.second==end) break;
    for(auto u : adj[temp.second]){
      if(mst[u.second]!=-1) continue;
      pq.push({temp.first+u.first,u.second});
    }
  }
  cout<< mst[end] << '\n';

    return 0;
}
