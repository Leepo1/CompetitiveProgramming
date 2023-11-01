#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
using ll = long long;
#define pii pair<int,pair<int,int> >
#define pi pair<int, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define mp make_pair
int parent[100005];
int value[100005];

int id = 0;
int company = 0;
map<string,int> ids;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(nullptr); cout.tie(nullptr);
  // ifstream cin ("TreeSalesi.txt");
  // ofstream cout ("usaco.out");
  int t; cin>> t;
  while(t--){
    id = 0;
    int n; cin>> n;
    for(int i = 0; i < n; i++){
      parent[i] = 0;
      value[i] = 0;
    }
    company++;
    cout << "COMPANY "  << company << '\n';
    for(int i = 0; i < n; i++){
      string req,f,s; cin >> req;
      if(req == "QUERY"){
        cin>> f;
        cout<< value[ids[f]] << '\n';
        continue;
      }
      cin >> f >> s;
      if(req == "ADD"){
        if(f == "ROOT"){
          ids[s] = id;
          parent[id] = -1;
          id++;
          continue;
        }
        ids[s] = id; 
        parent[id] = ids[f];
        id++;
        continue;
      }
      if(req == "SALE"){
        int curr = ids[f];
        while(true){
          value[curr]+=stoi(s);
          curr = parent[curr];
          if(curr == -1) break;
        }
      }
    }
  }
  return 0;
}
