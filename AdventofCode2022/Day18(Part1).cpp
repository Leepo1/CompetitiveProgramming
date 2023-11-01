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

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("Day18i.txt");
  ofstream cout("Day18o.txt");
  vector<int> xs;
  vector<int> ys;
  vector<int> zs;
  int x,y,z;
  while(cin>> x >> y >> z){
    xs.push_back(x); ys.push_back(y); zs.push_back(z);
  }
  int sa= xs.size()*6;
  for(int i=0; i<xs.size(); i++){
    for(int j=i+1; j<xs.size(); j++){
      if(touch(xs[i],ys[i],zs[i],xs[j],ys[j],zs[j])) sa-=2;
    }
  }
  cout<< sa << '\n';
    return 0;
}
