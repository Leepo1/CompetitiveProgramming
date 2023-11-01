#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <iomanip>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int,int> pi;
typedef long long ll;
typedef pair<int,pair<int,int> > pii;


int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  cout.tie(0);
  ifstream cin("coffeei.txt");
  ofstream cout("coffeeo.txt");
  int c;
  cin>> c;
  while(c--){
    int n , m, p;
    cin>> n >> m >> p;

    long long adj[n+5][n+5];
    for(int i=1; i<n+1; i++){
      for(int j=1; j<n+1; j++){
        adj[i][j]=500000000000000;
      }
      adj[i][i]=0;
    }



  
    for(int i=0; i<m; i++){
      int a, b ,d;
      cin>> a >> b >> d;
      adj[a][b]=d;
      adj[b][a]=d;
    }

    for(int k=1; k<n+1; k++){
      for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
          adj[i][j]=min(adj[i][k]+adj[k][j], adj[i][j]);
        }
      }
    }

    for(int i=0; i<p; i++){
      int h,c,w;
      cin >> h >> c >> w;
      if(adj[h][w]== 500000000000000){
        cout<< -1 << '\n';
      }else{
        long long answer=0;
        answer+= adj[h][c]+adj[c][w];
        cout<< answer << '\n';
      }
    }
  }

    return 0;
}
