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


vector<int> adj[1005];
map<int,int> occur;
int main (){

//ifstream cin ("usaco.in")
//ofstream cout ("usaco.out")
  int t; cin>> t;
  while(t--){
    //Clear adj and occur
    for(int i=0; i<1005; i++) adj[i].clear();
    occur.clear();

    int v,e; cin>> v >> e;
    for(int i=0; i<e; i++){
      int a,b; cin>> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    for(int i=1; i<=v; i++){
      occur[adj[i].size()]++;
    }
    int x = (v-occur[1]-1);
    int y = (v-x-1)/x;
    cout<< x << " " << y << '\n';
  }


  return 0;

}
