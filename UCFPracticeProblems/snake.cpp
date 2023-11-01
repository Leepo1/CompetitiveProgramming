#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
using ll = long long;
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

struct node{
  int l,r,lazy;
  int hs;
  node *left = nullptr;
  node *right = nullptr;

  node(){
    l = 0;
    r = 0;
    lazy = 0;
    hs = 0;
  }
  void lazyupdate(int dif){
    lazy += dif;
    hs +=  dif;
  }
  void prop(){
    if(!lazy) return;
    left->lazyupdate(lazy);
    right->lazyupdate(lazy);
    lazy = 0;
  }
  void build(int L, int R){
    l  = L;
    r = R;
    if(L == R){
      return;
    }
    int m  = L + (R - L) / 2; 
    left = new node();
    right = new node();
    left->build(L,m);
    right->build(m+1,R);
  }

  void update(int dl, int dr, int v){
    if(l > dr or r < dl) return;
    if(dl <= l and r <= dr){
      hs += v;
      lazy += v;
      return;
    }
    // Partial so find which node needs to have lazy propogated into it
    prop();
    left->update(dl,dr,v);
    right->update(dl,dr,v);
    hs = max(left->hs,right->hs);
    return;
  }
  int query(int dl, int dr){
    if(l > dr or r < dl) return 0;
    if(dl <= l and r <= dr) return hs;
    prop();
    return max(left->query(dl,dr),right->query(dl,dr));
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // ifstream cin("snakei.txt");
  int t; cin >> t;
  while(t--){
    int n,q; cin >> n >> q;
    node *start = new node();
    start->build(0,n-1);
    for(int i = 0; i < q; i++){
      int b,e,v; cin >> b >> e >> v;
      start->update(b-1,e-1,1);
      int see = start->query(0,n-1);
      if(see >= v){
        cout << "blocked" << '\n';
      } else {
        cout<< "hit" << '\n';
      }
    }
  }
  return 0;
}
