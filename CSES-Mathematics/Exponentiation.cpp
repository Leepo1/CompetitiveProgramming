#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
const int MOD = 1e9 + 7;

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return (((res * res) % MOD) * a) % (MOD);
    else
        return (res * res) % (MOD);
}

 long long binpow2(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        ll a; ll b; cin >> a >> b;
        cout << binpow(a,b) << '\n';
    }

   

  return 0;
}
