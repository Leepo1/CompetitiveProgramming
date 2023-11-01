#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve() {
    int n; cin >> n;
    ll a[n], l;
    map<ll, ll> c;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) {
        cin >> l;
        a[i] -= l;
    }

    ll pre[n + 1];
    pre[0] = 0;
    c[0]++;
    for (int i=1;i<=n;i++) {
        pre[i] = a[i-1];
        pre[i] += pre[i-1];
        c[pre[i]]++;
    }
    //cout << c[-1] << " " << c[1] << " " << c[0] << "\n";
    ll ans = 0;
    //sort(pre.begin(), pre.end());
    for (ll x : pre) {
        ans += (c[x]*(c[x]-1))/2;
        c[x] = 0;
    }

    return ans;
}

int main() {
    int t; cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }

    return 0;
}
