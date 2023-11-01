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
        int n; cin >> n;
        if(n <= 6 || n == 9){
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        if(n % 3 == 1 || n % 3 == 2){
            cout << n - 3 << " " << 1 <<  " " << 2 << '\n';
        }else if(n % 3 == 0){
            cout << n - 5 << " " << 1 << " " << 4 << '\n';
        }
    }

  return 0;
}
