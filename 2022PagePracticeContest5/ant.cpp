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
typedef pair<int,pair<int,int>> pii;


int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  cout.tie(0);
  ifstream cin("anti.txt");
  ofstream cout("anto.txt");
  int c;
  cin>> c;

  while(c--){
    int dirx=-1;
    int diry=0;
    int xpos=0;
    int ypos=0;
    int n;
    cin>> n;

    bool grid[n][2][n][2]={false};
    for(int i=0; i<n; i++){
      int s=0;
      int f=0;
      if(xpos<0){
        s=1;
      }
      if(ypos<0){
        f=1;
      }


      if(grid[xpos][s][ypos][f]){
        if(dirx==0){
          dirx= -1*diry;
          diry=0;
        }else{
          diry=dirx;
          dirx=0;
        }
      }else{
        if(dirx==0){
          dirx=diry;
          diry=0;
        }else{
          diry= -1*dirx;
          dirx=0;
        }
      }


      grid[abs(xpos)][s][abs(ypos)][f]= !grid[abs(xpos)][s][abs(ypos)][f];
      xpos+=dirx;
      ypos+=diry;
    }
    cout<<  xpos << " " << ypos << '\n';
  }
    return 0;
}
