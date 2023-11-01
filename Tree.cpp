#include <bits/stdc++.h>
using namespace std;
int depth[200005];
int up[200005][20];
vector<int> adj[200005];
// Euler Tour
const int n = 1e5;
int timer = 0;

// Euler Tour
int pre[n],post[n];
int euler_tour(int node, int par){
    depth[node] = depth[par] + 1;
    pre[node] = timer++;
    up[node][0] = par;
    for(int i = 1; i < 20; i++) up[node][i] = up[up[node][i-1]][i-1];
    for(auto u : adj[node]){
        if(u == par) continue;
        euler_tour(u,node);
    }
    post[node] = timer - 1;
}

// Binary Lifting
int jump(int x, int d){
    for(int i = 0; i < 20; i++){
        if((d & (1 << i))) x = up[x][i];
    }
    return x;
}

// LCA
int LCA(int a, int b){
    if(depth[a] < depth[b]) swap(a,b);

    a = jump(a, depth[a] - depth[b]);
    if(a == b) return a;

    for(int i = 0; i < 20; i++)
}
int main(){



    return 0;
}