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
    int xp,m; cin >> xp >> m;
    int p1,p2; cin >> p1 >> p2;
    int q1,q2; cin >> q1 >> q2;
    for(int i = 0; i < m; i++){
        int temp; cin >> temp;
        int used = temp - p1;
        int unused = temp;
        int cost1;
        if(used < 0){
            cost1 = p2;
        }else{
            if(used % q1 == 0) cost1 = (used / q1) * q2 + p2;
            else cost1 = ((used / q1) + 1) * q2 + p2;
        }
        
        int cost2;
        if(unused % q1 == 0) cost2 = (unused / q1) * q2;
        else cost2 = ((unused / q1) + 1) * q2;

        xp -= min(cost1,cost2);
        if(xp <= 0){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    
  return 0;
}
