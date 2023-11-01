#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long 
int dx[4] = {1,-1,0,0}; 
int dy[4] = {0,0,1,-1};


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int orig[2*n];
    int porig[2*n + 1];
    for(int i = 0 ; i < n; i++){
        cin >> orig[i]; orig[i + n] = orig[i];
    }
    orig[n] = orig[0];
    ll ans = 0;
    ll firstproduct = 0;
    porig[0] = 0;
    for(int i = 1; i < 2*n + 2; i++){
        porig[i] = porig[i - 1] + orig[i - 1];
    }
    for(int i = 1; i <= n; i++){
        firstproduct += i*orig[i-1];
        ans = max(ans, firstproduct);
    }
    ll lastproduct = firstproduct;
    for(int i = 1; i < n; i++){
        // Previous number's multiplier jumps up by (n-1)
        lastproduct += (n - 1)*(orig[i - 1]);
        // All other numbers multipliers go down by one 
        // -> in other words we lose one of each
        lastproduct -= (porig[i + (n - 1)] - porig[i]);
        ans = max(lastproduct,ans);         
    }
    cout << ans << '\n';

  return 0;
}
