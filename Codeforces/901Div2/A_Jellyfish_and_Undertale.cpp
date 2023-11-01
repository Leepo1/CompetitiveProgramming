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
        int a,b,n; cin >> a >> b >> n;
        int ans = b;
        for(int i = 0; i <n; i++){
            int temp; cin >> temp;
            ans += min(temp,a - 1);
        }
        cout << ans  << '\n';
    }

  return 0;
}
