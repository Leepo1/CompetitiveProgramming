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

ii shots[1005];
ii block[1005];

double di(int x, int y, int w, int z){
  return sqrt(abs((w-x)*(w-x))+abs((z-y)*(z-y)));
}

bool check(double l, int n){
  int blocked=0;
  for(int i=0; i<n; i++){
    if(di(shots[i].first,shots[i].second,block[i].first,block[i].second)<=l){
      blocked++;
    } // Maybe do abs value of difference is really low
  }
  if(n%2==0){
    if(blocked>=n/2) return true;
    return false;
  }
  if(blocked>= n/2 + 1) return true;
  return false;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("DillardsandLeeptardsPenaltiesi.txt");
  ofstream cout("DillardsandLeeptardsPenaltieso.txt");
  int n; cin>> n;
  double R;
  for(int i=0; i<n; i++){
    cin>> shots[i].first >> shots[i].second >> block[i].first >> block[i].second;
    if(i==0) R= di(shots[i].first,shots[i].second,block[i].first,block[i].second);
    R= max(R,di(shots[i].first,shots[i].second,block[i].first,block[i].second));
  }

  double L=0;
  double ans;
  for(int i=0; i<64; i++){
    double M = L + (R-L)/2;
    if(check(M)){
      R=M;
      ans=M;
    }else{
      L=M;
    }
  }

  cout<< "Dillard's arms are gonna have to be at least " << M << "cm long" << '\n';
    return 0;
}
