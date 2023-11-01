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
        vector<int> v;
        int curr = 0; int gaps = 0;
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            if(a > 0){
                cout << 1 << '\n';
                return;
            } 
            v.push_back(a);
            gaps += a - curr;
            curr = a + 1;
        }
        int moves = n + 1;

    }   

  return 0;
}
