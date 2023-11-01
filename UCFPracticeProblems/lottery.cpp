#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
bool whichtry = true;

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
  // ifstream cin ("usaco.in"); ofstream cout ("usaco.out");
    int t; cin >> t;
    int lottery = 0;
    while(t--){
        lottery++;
        cout << "Lottery #" <<  lottery << ":" << endl ;
        whichtry = true;
        int n; cin >> n;
        Node *t1 = new Node();
        Node *t2 = new Node();
        for(int i = 0; i < n; i++){
            int q; string s; cin>> q;
            if(q == 1)
            {
                cin>> s;
                if(whichtry){
                    t1->add(s,0);
                    reverse(s.begin(),s.end());
                    t2->add(s,0);
                }else{
                    t2->add(s,0);
                    reverse(s.begin(),s.end());
                    t1->add(s,0);
                }
            }
            else if(q == 2){
                cin>> s;
                if(whichtry) cout << t1->query(s,0) << endl;
                else cout << t2->query(s,0) << endl;
            }else{
                whichtry = !whichtry;
            }
        }
        cout << '\n';
    }
  return 0;
}
