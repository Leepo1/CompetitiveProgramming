#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
int dx[4] = {1,-1,0,0}; 
int dy[4] = {0,0,1,-1};
int n;
int dp[200005];
int arr[200005];
int currsize = -1;
int recurse(int pos){
    if(dp[pos] != -1) return dp[pos];
    if(n - pos - 1 == arr[pos]){
        dp[pos] = 0;
        return dp[pos];
    }
    if(pos == n - 1){
        dp[pos] = 1;
        return dp[pos];
    }
    if(n - pos - 1 < arr[pos]){
        dp[pos] = 1 + recurse(pos + 1);
        return dp[pos];
    }else{
        dp[pos] = min(1 + recurse(pos + 1), recurse(pos + arr[pos] + 1));
        return dp[pos];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            dp[i] = -1;
            cin >> arr[i];
        }
        cout << recurse(0) << '\n';
    }

  return 0;
}
