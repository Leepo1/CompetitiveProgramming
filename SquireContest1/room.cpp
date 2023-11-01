#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define INF 2000000000
using namespace std;
using ll = long long;
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
int n, m;
int space = 0;
vector<vector<int> > grid;
map<int, int> ids;
int dx[4] = {1, -1, 0, 0};

int dy[4] = {0, 0, 1, -1};

int id = 1;
bool inbounds(int x, int y) { return (x >= 0 && y >= 0 && x < n && y < m); }

void floodfill(int x, int y, int parent) {
  space++;
  grid[x][y] = parent;
  for (int d = 0; d < 4; d++) {
    int nx = x + dx[d];
    int ny = y + dy[d];
    if (inbounds(nx, ny) && grid[nx][ny] == 0) {
      floodfill(nx, ny, parent);
    }
  }
}

int main() {
  // ifstream cin("roomi.txt");
  int t;
  cin >> t;
  while (t--) {
    ids.clear();
    ids[-1] = 0;
    id = 1;
    vector<vector<int> > temp;
    grid = temp;
    int answer = 0;
    
    cin >> n >> m;
    grid.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char a; cin >> a;
        if (a == '.') grid[i][j] = 0;
        else if (a == '#') grid[i][j] = -1;
      }
    }
    
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 0){
            floodfill(i, j, id);
            answer = max(answer, space);
            ids[id] = space;
            space = 0;
            id++;
        }
            
      }
    }
   
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == -1) {
          int amount = 1;
          set<int> used;
          for (int d = 0; d < 4; d++) {
            int nx = i + dx[d];
            int ny = j + dy[d];
            if (inbounds(nx, ny) && grid[nx][ny] != -1) {
                if(used.find(grid[nx][ny])!=used.end()) continue;
                used.insert(grid[nx][ny]);
                amount += ids[grid[nx][ny]];
            }
          }
          answer = max(answer, amount);
        }
      }
    }
    cout << answer << '\n';
    
  }

  return 0;
}
