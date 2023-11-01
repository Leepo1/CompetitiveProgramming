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
        string s; cin >> s;
        int l = s.size();
        int req = 0;
        int twos = 0;
        
        for(int i = 0; i < l/2; i++){
            if(s[i] != s[(n - 1) - i]){
                req += 1;
                continue;
            }
            twos++;
        }
        
        for(int i = 0; i <= n; i++){
            if(i < req){
                cout << "0";
                continue;
            }
            int num = i - req;
            if(num % 2 == 0 && num / 2 <= twos){
                cout << "1";
            }else if(l % 2 == 1){
                num -= 1;
                if(num % 2 == 0 && num / 2 <= twos){
                cout << "1";
            }else{
                cout << "0";
            }
            }else{
                cout << "0";
            }
        }
        cout << '\n';
    }

  return 0;
}
