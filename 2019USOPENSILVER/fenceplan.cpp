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

vector<int> adj[100005];
ii pos[100005];
ii connections[100005];
bool visited[100005];

int minx;
int maxx;
int miny;
int maxy;

void dfs(int node){
    minx= min(minx,pos[node].first);
    maxx= max(maxx, pos[node].first);
    miny=min(miny, pos[node].second);
    maxy= max(maxy,pos[node].second);
    visited[node]=true;
    for(auto u : adj[node]){
        if(visited[u]) continue;
        dfs(u);
    }
}

int perimeter(int n){
    int answer= 500000;
    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        minx=pos[i].first;
        maxx=pos[i].first;
        miny=pos[i].second;
        maxy=pos[i].second;
        dfs(i);
        
        if(maxx-minx==0){
            answer=min(answer,maxy-miny);
        }else if(maxy-miny==0){
            answer=min(answer,maxx-minx);
        }else{
            answer=min(answer,2*(maxx-minx)+2*(maxy-miny));
        }
        
    }
    return answer;

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  //ifstream cin("fenceplani.txt");
  //ofstream cout("fenceplano.txt");
  ifstream cin("fenceplan.in");
  ofstream cout("fenceplan.out");
    int n, c;
    cin>> n >> c;

    for(int i=0; i<n; i++){
       cin>> pos[i].first >> pos[i].second;
    }

    for(int i=0; i<c; i++){
       int a,b;
       cin>> a >> b;
       adj[a-1].push_back(b-1);
       adj[b-1].push_back(a-1);
    }
    cout<< perimeter(n) << '\n';
    return 0;
}
