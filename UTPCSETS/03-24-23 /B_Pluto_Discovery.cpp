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
    int ans = 0;
    for(int i = 1; i <= n ; i++){
        ans += n % i;
    }
    cout << ans << '\n';

  return 0;
}
