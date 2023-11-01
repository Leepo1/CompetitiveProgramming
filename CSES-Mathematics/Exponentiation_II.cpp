#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
int MOD = 1e9 + 6;
long long binpow(long long a, long long b){
    if(b == 0) return 1;
    long long curr = binpow(a, b/2) % MOD;
    if(b % 2 == 1){
        return ((((curr * curr) % MOD) * a) % MOD); 
    }else{
        return ((curr * curr) % MOD);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        ll a,b,c; cin >> a >> b >> c;
        MOD = 1e9 + 6;
        ll temp = binpow(b,c);
        MOD = 1e9 + 7;
        cout << binpow(a, temp) << '\n';
    }

  return 0;
}
