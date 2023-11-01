#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
using ll = long long;
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

struct Node{
    Node *c[26];
    int words;
    Node(){
        fill(c,c+26,nullptr);
        words = 0;
    }
    void add(string s, int ind){
        words++;
        //base case?
        if (ind == sz(s)) {
            return;
        }
        int to  = s[ind] - 'a';
        //node not created?
        if(!c[to]) c[to] = new Node();
        //next child?
        c[to]->add(s, ind+1);
    }

    int query(string prefix, int ind){
        if(ind == prefix.size()) return words;
        int to = prefix[ind] - 'a';
        if(!c[to]) return 0;
       return c[to]->query(prefix, ind+1);
    }
    
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // ifstream cin ("usaco.in");
  // ofstream cout ("usaco.out");
  
  return 0;
}
