#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
string s;
vector<int> adj[100005];
int hcount = 0;
int gcount = 0;

bool dfs(int curr, int desired, int prev, char breed){
    if(s[curr] == 'H') hcount+=1;
    if(s[curr] == 'G') gcount+=1;
    if(curr == desired){
        if(hcount > 0 && breed == 'H') return true;
        if(gcount > 0 && breed == 'G') return true;
        return false;
    }
    for(auto u : adj[curr]){
        if(u == prev) continue;
        if(dfs(u,desired,curr,breed)) return true;
        if(s[u] == 'H') hcount-=1;
        else gcount-=1;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ifstream cin("milkvisits.in");
    ofstream cout("milkvisits.out");
    int n,m; cin >> n >> m;
    cin >> s;
    for(int i = 0; i < n - 1; i++){
        int a,b; cin >> a >> b;
        a-=1; b-=1;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        a-=1; b-=1;
        char temp; cin >> temp;
        gcount = 0; hcount = 0;
        if(dfs(a,b, -1, temp)) cout << "1";
        else cout << "0";
    }


  return 0;
}
