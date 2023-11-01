#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 1e9 + 7;
string s;
int ten[100005];
struct Node {
  int l, r;
  int digits;
  long long modded;
  Node *left = nullptr;
  Node *right = nullptr;
  Node(){
    l = 0;
    r = 0;

    modded = 0;
  }
  void build(int L, int R) {
    l = L;
    r = R;
    if (l == r) {
      string temp = "";
      temp += s[l];
      modded = stoi(temp);
      return;
    }

    int m = l + (r - l) / 2;
    left = new Node();
    right = new Node();
    left->build(l, m);
    right->build(m + 1, r);
    
  }
  void update(int x, string add) {
    if (l > x || r < x)
      return;
    if (l == r) {
      number = add;
      return;
    }

    left->update(x, add);
    right->update(x, add);
    number = left->number + right->number;
    modded = (left->modded*(ten[max((int)right->number.size(),1)])) + right->modded) % (mod);
  }
  long long query(int dl, int dr) {
    if (l > dr || r < dl)
      return 0;
    if (dl <= l && r <= dr)
      return modded;
     return (left->query(dl,dr)*(ten[max((int)right->number.size(),1)]) + right->query(dl,dr)) % (mod);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t; cin>> t;
  int curr = 1;
  for(int i = 0; i < 100005; i++){
    ten[i] = curr % mod;
    curr *= 10;
    curr %= mod;
  }
  while(t--){
    cin>> s;
    int n  = s.size();
    Node *start =  new Node();
    start->build(0,n-1);
    int q; cin>> q;
    for(int i = 0; i < q; i++){
      int a,b,c; cin>> a; 
      if(a == 1){
        cin >> b >> c;
        cout << start->query(b-1,c-1) << '\n'; 
      }else{
        cin>> b;
        string temp; cin>> temp;
        start->update(b-1,temp);
      }
    }

  }

  return 0;
}
