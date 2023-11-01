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

bool touch(int x, int y ,int z, int x1, int y1, int z1){
  if(x==x1 && y==y1 && abs(z-z1)==1) return true;
  if(x==x1 && z==z1 && abs(y-y1)==1) return true;
  if(y==y1 && z==z1 && abs(x-x1)==1) return true;
  return false;
}
int dx[6] = {-1,0,0,1,0,0};
int dy[6] = {0,-1,0,0,1,0};
int dz[6] = {0,0,-1,0,0,1};


vector<int> xs;
vector<int> ys;
vector<int> zs;
bool touchesair[25][25][25];

bool iscube(int a, int b, int c){
  for(int i=0; i<xs.size(); i++){
    if(a==xs[i] && b==ys[i] && c==zs[i]) return true;
  }
  return false;
}

void floodfill(int a, int b, int c){
  for(int d=0; d<3; d++){
    a+=dx[d];
    b+=dy[d];
    c+=dz[d];
    if(a<0 || b<0 || c<0) continue;
    if(iscube(a,b,c)) continue;
    if(touchesair[a][b][c]) continue;
    touchesair[a][b][c]=true;
    floodfill(a,b,c);
  }
}

void floodfillv2(int a, int b, int c){
  for(int d=0; d<3; d++){
    a+= dx[d+3];
    b+= dy[d+3];
    c+= dz[d+3];
    if(a>20 || b>20 || c>20) continue;
    if(iscube(a,b,c)) continue;
    if(touchesair[a][b][c]) continue;
    touchesair[a][b][c]=true;
    floodfill(a,b,c);
  }
}

bool floodfillv3(int a, int b, int c){
  for(int d=0; d<6; d++){
    a+= dx[d];
    b+= dy[d];
    c+= dz[d];
    if(a>=20 || a<=0 || b>=20 || b<=0 || c>=20 || c<=0) return true;
    if(touchesair[a][b][c]) return true;
    if(iscube(a,b,c)) continue;
    floodfillv3(a,b,c);
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("Day18i.txt");
  ofstream cout("Day18o.txt");

  int x,y,z;
  int maxx=0, maxy=0, maxz=0;
  while(cin>> x >> y >> z){
    maxx = max(maxx,x); maxy = max(maxy,y); maxz = max(maxz,z);
    xs.push_back(x); ys.push_back(y); zs.push_back(z);
  }
  int sa= xs.size()*6;
  for(int i=0; i<xs.size(); i++){
    for(int j=i+1; j<xs.size(); j++){
      if(touch(xs[i],ys[i],zs[i],xs[j],ys[j],zs[j])) sa-=2;
    }
  }
  int ox = maxx+1, oy = maxy+1, oz = maxz+1;
  touchesair[ox][oy][oz]=true;
  touchesair[0][0][0]=true;
  floodfill(ox,oy,oz);
  //floodfillv2(0,0,0);
  for(int i=0; i<xs.size(); i++){
    int p=xs[i],q=ys[i],r=zs[i];
    for(int d=0; d<6; d++){
      int np = p+ dx[d];
      int nq= q + dy[d];
      int nr = r +dz[d];
      if(iscube(np,nq,nr)) continue;
      if(!touchesair[np][nq][nr]) sa-=1;
    }
  }
  cout<< sa << '\n';
    return 0;
}
