#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  //ifstream cin("reduce.in");
  //ofstream cout("reduce.out");
  int n;
  cin>> n;


  vector<int> xs;
  vector<int> ys;
  int x[n];
  int y[n];

  for(int i=0; i<n; i++){
    int a,b;
    cin>> a >> b;
    x[i]=a;
    y[i]=b;
    xs.push_back(a);
    ys.push_back(b);
  }

  sort(xs.begin(),xs.end());
  sort(ys.begin(),ys.end());

  int area= ((xs[n-1]-xs[0])*(ys[n-1]-ys[0]));

  for(int i=0; i<n; i++){
    int mx=xs[0];
    if(x[i]==xs[0]){
      mx=xs[1];
    }
    int mmx=xs[n-1];
    if(x[i]==xs[n-1]){
      mmx=xs[n-2];
    }
    int my=ys[0];
    if(y[i]==ys[0]){
      my= ys[1];
    }
    int mmy=ys[n-1];
    if(y[i]==ys[n-1]){
      mmy=ys[n-2];
    }
    area= min(area,(mmx-mx)*(mmy-my));
  }

  cout<< area << '\n';
  return 0;
}
