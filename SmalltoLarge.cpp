#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
using ll = long long;
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

int n; 
vector<int> col;
vector<vector<int> > edges;
vector<int> ans;
set<int> *merge(set<int> *A, set<int> *B){
    // make A the smaller one
    if(!(A->size() <= B->size())) swap(A,B);
    // merge all of A into B
    for(int x : *A) B->insert(x);
    return B;
}

set<int> *dfs(int idx, int par){
    set<int> *out = new set<int>();
    out->insert(col[idx]);
    for(int next : edges[idx]){
        if(next == par) continue;

        set<int> *get = dfs(next, idx);
        out = merge(out, get);
    }


    return out;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // ifstream cin ("usaco.in"); ofstream cout ("usaco.out");
  cin >> n;
  col = vector<int>(n);
  for(int i = 0; i < n; i++) cin >> col[i];

  edges = vector<vector<int> >(n);
  for(int i = 0; i < n - 1; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  ans = vector<int>(n);
  dfs(0,-1);

  return 0;
}
