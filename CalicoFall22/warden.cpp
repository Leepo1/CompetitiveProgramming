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

double distance(double x, double y, double x1, double y1){
  return sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y));
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("wardeni.txt");
  ofstream cout("wardeno.txt");
  int t; cin>> t;
  while(t--){
    vector<double> data;
    double L=-1e6, R=1e6;
    while(R-L>5){
      cout<< "P" << L << " " << 0 << flush;
      double d; cin>> d;
      data.push_back(d);
      cout<< "P" << R << " " << 0 << flush;
      double d1; cin>> d1;
      if(d<d1) R*=1/2;
    }
  }

    return 0;
}
