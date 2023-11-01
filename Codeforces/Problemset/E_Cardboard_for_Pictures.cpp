#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, pair<ll, ll>>
#define pi pair<ll, ll>
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define ll long long 


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,c; cin >> n >> c;
        vector<ll> v;
        for(ll i = 0; i < n; i++){
             ll a; cin >> a; v.push_back(a);
        }
        ll L = 1, R = 1e9;
        ll ans = 1;
        while(L <= R){
            ll M = L + (R - L) / 2;
            ll total = 0;
            for(ll i = 0; i < n; i++){
                total  += (v[i] + 2*M)*(v[i] + 2*M);
                if(total > c) break;
            }
            if (total == c){
                 ans = M;
                 break;
            }else if(total > c){
                R = M - 1;
            }else{
                L = M + 1;
            }
        }
        cout << ans << '\n';
    }
    
  return 0;
}
