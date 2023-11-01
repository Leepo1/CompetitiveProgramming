#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,d; cin >> n >> d;
    vector<int> streaks;
    int curr = 1;
    int prev; cin>> prev;
    for(int i = 1; i < n; i++){
        int next; cin >> next;
        if(next <= prev) curr++;
        else{
            streaks.push_back(curr);
            prev = next; 
            curr = 1;
        }  
    }
    streaks.push_back(curr);
    sort(streaks.begin(),streaks.end());
    reverse(streaks.begin(), streaks.end());
    int answer = 0;
    int s = streaks.size();
    for(int i  = 0; i < min(d,s); i++){
        answer += streaks[i];
    }
    cout << answer << '\n';

  return 0;
}
