#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n,m,k; cin >> n >> m >> k;
        int j[n];
        int g[n];
        int jmax = INT_MIN;
        int jmin = INT_MAX;
        int jsum = 0;
        for(int i = 0; i < n; i++){
            cin >> j[i]; jsum += j[i];
            jmax = max(jmax,j[i]);
            jmin = min(jmin,j[i]);
        }
        int gmax = INT_MIN;
        int gmin = INT_MAX;
        int gsum = 0;
        for(int i = 0; i < n; i++){
            cin >> g[i]; gsum += g[i];
            gmax = max(gmax,g[i]);
            gmin = min(gmin,g[i]);
        }
        if(k % 2 == 1){
            cout << jsum + (gmax - jmin) << '\n';  
            continue;
        }else{
            cout << jsum - max(jmax,gmax) + min(jmin,gmin) << '\n';
        }
    }

  return 0;
}
