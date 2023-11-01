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
        int s,d,k; cin >> s >> d >> k;
        int buns = 0;
        int patties = 0;
        int cheese = 0;
        buns += (s*2 + d*2);
        cheese += (s + 2*d);
        patties += (s + 2*d);
        cout << "Case #" << cased << ": " << ((buns >= k + 1 && cheese >=k && patties >=k) ? "YES" : "NO") << '\n';
    }

  return 0;
}
