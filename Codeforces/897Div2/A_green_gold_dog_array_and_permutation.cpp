#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >>  t;
    while(t--){
        int n; cin >> n;
        vector<int> v;
        map<int, vector<int>> corres;
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            v.push_back(a);
        }
        
        vector<int> u = v;
        sort(v.begin(),v.end());
        for(int i = 0; i < n; i++){
            corres[v[i]].push_back(n - i);
        }
        
        for(int i = 0; i < n; i++){
            cout << corres[u[i]][corres[u[i]].size() - 1] << " ";
            corres[u[i]].pop_back();
        }
        cout << '\n';
        
    }

  return 0;
}
