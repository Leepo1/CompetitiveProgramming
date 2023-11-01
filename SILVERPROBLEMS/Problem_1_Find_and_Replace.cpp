#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
map<char,char> act;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        for(char i = 'a'; i <= 'z'; i++) act[i] = i;
        for(char i = 'A'; i <= 'Z'; i++) act[i] = i;
        string s,desired; cin >> s >> desired;
        int strokes = 0;
        bool works = true;
        for(int i = 0 ; i < s.size(); i++){
            if(act[s[i]] != desired[i]){
                if(act[s[i]] != s[i]){
                    cout << -1 << '\n';
                    works = false;
                    break;
                }
                act[s[i]] = desired[i];
                strokes++;
            }
        }
        if(works) cout << strokes << '\n';
    }
  return 0;
}
