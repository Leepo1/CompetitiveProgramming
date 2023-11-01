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
    while(t--){
      int a,b,c; cin >> a >> b >> c;
      int temp = a;
      a = min(a , b);
      b = max(temp, b);
      int value = (a + b) / 2;
      if( (value - a) % c == 0 && a % 2 == b % 2) cout << (value - a) / c << '\n';
      else cout << (value - a) / c + 1 << '\n';
    }

  return 0;
}
