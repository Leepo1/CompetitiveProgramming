#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int arr[n];
    int ans = -1;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 1; i < n - 1; i++){
        if(arr[i] < arr[i - 1] && arr[i] < arr[i+1]) ans = max(ans, arr[i]);
        
    }
    cout << ans << '\n';
    

  return 0;
}
