#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

char colors[1005][1005];
int rankers[1005][1005];
unordered_map<int, int> lib;
unordered_map<int, int> mp;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n,m,q; 
int ranker = 0;

void flood(int lx, int ly, char color){
    rankers[lx][ly] = ranker;
    for(int d=0;d<4;d++){
        int nx = lx + dx[d];
        int ny = ly + dy[d];
        if(nx < 0 || ny < 0) continue;
        if(nx >= n || ny >= m) continue;
        if(rankers[nx][ny] == -1 && colors[nx][ny] == color) flood(nx, ny, color);
        if(colors[nx][ny] == '.') lib[ranker]+=1;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n>>m>>q;
   
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>colors[i][j];
            rankers[i][j]=-1;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(rankers[i][j]==-1){
                flood(i, j, colors[i][j]);
                
                ranker++;
            }
        }
    }

    for(int i = 0; i<q;i++){
        mp.clear();
        vector<int> v;
        char cc;
        int x, y; cin>>cc>>x>>y;
        x--;
        y--;
        bool works = false;
        bool same = false;
        for(int d=0;d<4;d++){
            int nx, ny;
            nx = x+dx[d];
            ny = y+dy[d];  
            if(nx<0||ny<0){
                continue;
            }
            if(nx>=n||ny>=m){
                continue;
            }
            if(colors[nx][ny] == '.'){
                works = true;
                break;
            }
            if(cc != colors[nx][ny]){
                continue;
            }
            same = true;
            mp[rankers[nx][ny]] += 1;
            v.push_back(rankers[nx][ny]);
        }
        if(works){
            cout << "Go!" << '\n';
            continue;
        }
        if(!same){
            cout<<"No go!"<<'\n';
            continue;
        }
        works = false;
        for(auto u : v){
            if(lib[u] > mp[u]){
                works = true;
                break;
            }
        }
        if (works){
            cout << "Go!" << '\n';
        }else {
            cout << "No go!" << '\n';
        }
    }

  return 0;
}
