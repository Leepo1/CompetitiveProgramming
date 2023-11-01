#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;

char grid[10000][10000];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("Day14i.txt");
  ofstream cout("Day14o.txt");


  string s;

  for(int i=0; i<10000; i++){
    for(int j=0; j<10000; j++){
      grid[i][j]='.';
    }
  }

  int highestx=0;

  while(getline(cin,s)){
    stringstream ss(s);
    int f,d;
    ss >> f >> d;
    int x = f;
    int y = d;
    while(ss >> f >> d){
      int nx = f;
      int ny = d;
      if(x==nx){
        for(int i=min(y,ny); i<=max(y,ny); i++){
          grid[i][x]='r';
          highestx=max(highestx,i);
        }
      }else{
        for(int i=min(x,nx); i<=max(x,nx); i++){
          grid[y][i]='r';
          highestx=max(highestx,y);
        }
      }
      x=nx;
      y=ny;
    }
  }
  for(int i=0; i<10000; i++){
    grid[highestx+2][i]='r';
  }
  int times=0;
  while(true){
    times++;
    int y=500;
    int x=0;
    if(grid[x][y]=='s'){
      break;
    }
      while(true){
        if(grid[x+1][y]=='.'){
          x++;
          continue;
        }else if((y-1)>=0 && grid[x+1][y-1]=='.'){
          y--;
          x++;
          continue;
        }else if(grid[x+1][y+1]=='.'){
          x++;
          y++;
          continue;
        }
        grid[x][y]='s';
        break;
      }
  }
  cout<< times-1 << '\n';
    return 0;
}
