#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    int cased = 0;
    while(t--){
        cased++;
        int r,c,a,b; cin >> r >> c >> a >> b;
        cout << "Case #" << cased << ": " << (r > c ? "YES" : "NO") << '\n';
    }
    

  return 0;
}
