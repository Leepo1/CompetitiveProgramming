#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
map<int,int> trap;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1; cin >> t;
    
    while(t--){
      int n; cin >> n;
      for(int i = 1; i <= 200; i++) trap[i] = 0;
      for(int i = 0; i < n; i++){
        int spot, dur; cin >> spot >> dur;
        if(trap[spot] == 0) trap[spot] = dur;
        else trap[spot] = min(trap[spot], dur);
      }
      int curr = 0;
      int furthestroom = INT_MAX;
      while(true){
          if(curr == furthestroom){
            cout << curr << '\n';
            break;
          }
        if(trap[curr] == 0){
          curr++;
          continue;
        }
        // seconds
        int value = 0;
        if(trap[curr] % 2 == 0) value = curr + trap[curr] / 2 - 1;
        else value = curr + trap[curr] / 2; 
        furthestroom = min(furthestroom, value);
        if(furthestroom == curr){
          cout << curr << '\n';
          break;
        }
        curr++;
      }
    }
    

  return 0;
}
