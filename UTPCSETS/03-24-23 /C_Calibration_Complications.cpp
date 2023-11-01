#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<ll> fr;
    vector<ll> sr;
    ll frmax = 1;
    ll srmin = INT_MAX;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll a; cin >> a; frmax = max(frmax, a);
        fr.push_back(a);
    }
    for(int i = 0; i < n; i++){
        ll a; cin >> a; srmin = min(srmin, a);
        sr.push_back(a);
    }
    if(frmax > srmin){
        cout << -1 << '\n';
        return 0;
    }
    for(int i = 0; i < n; i++){
        ans += abs(fr[i] - frmax);
        ans += abs(sr[i] - frmax);
    }
    cout << ans << '\n';
  return 0;
}
