#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
vector<int> adj[205];
bool visited[205];

int nodes = 0;
void dfs(int node){
    visited[node] = true;
    nodes++;
    for(auto u : adj[node]){
        if(visited[u]) continue;
        dfs(u);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ifstream cin("moocast.in");
    ofstream cout("moocast.out");
    int n; cin >> n;
    vector<pi> locations(n);
    vector<int> power(n);
    for(int i = 0; i < n; i++){
        cin >> locations[i].first >> locations[i].second >> power[i] ;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            int xdist = abs(locations[i].first - locations[j].first);
            int ydist = abs(locations[i].second - locations[j].second);
            if(xdist*xdist + ydist*ydist <= power[i]*power[i]) adj[i].push_back(j); 
        }
    }
    int answer = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 205; j++) visited[j] = false;
        nodes = 0;
        dfs(i);
        answer = max(answer,nodes);
    }
    cout << answer << '\n';
  return 0;
}
