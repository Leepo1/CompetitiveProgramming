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
  return abs(p2.first-p1.first)+abs(p2.second-p1.second);
}

map<string, vector<string> > adj;
map<string, ii> pos;
map<string, int> range;
map<string,bool> visited;

bool dfs(string name, string end){
  visited[name]=true;
  for(auto u : adj[name]){
    if(visited[u]) continue;
    if(u==end) return true;
    if(dfs(u,end)) return true;
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("PassingQueries1i.txt");
  ofstream cout("PassingQueries1o.txt");

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
    visited[names[i]]=false;
    for(int j=0; j<N; j++){
      if(j==i) continue;
      if(distance(pos[names[i]],pos[names[j]]) <= range[names[i]]) adj[names[i]].push_back(names[j]);
    }
  }

  string start, end; cin>> start >> end;
  if(dfs(start,end)){
    cout<< "PASS" << '\n';
  }else{
    cout<< "Maybe somebody else" << '\n';
  }

    return 0;
}
