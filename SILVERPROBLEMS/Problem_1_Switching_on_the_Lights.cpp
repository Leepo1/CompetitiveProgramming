#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n;
map<pi, vector<pi>> adj;
map<pi,bool> visited;
map<pi, bool> lit;

int lits = 1;
void dfs(pi point){
    cout << point.first << " " << point.second << '\n';
    visited[point] = true;
    for(auto u : adj[point]){
        if(lit[u] == true) continue;
        lits++; lit[u] = true;
    }
    for(int d = 0; d < 4; d++){
        int nx = point.first + dx[d];
        int ny = point.second + dy[d];
        if(nx > 0 && ny > 0 && nx <= n && ny <= n){
            pi temp; temp.first = nx; temp.second = ny;
            if(lit[temp] && !visited[temp]) dfs(temp);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int m; cin >> n >> m;
    pi temp; temp.first = 1; temp.second = 1;
    lit[temp] = true;
    for(int i = 0; i < m; i++){
        pi f,s; cin >> f.first >> f.second >> s.first >> s.second;
        adj[f].push_back(s);
    }
    dfs(temp);
    cout << lits << '\n';

  return 0;
}
