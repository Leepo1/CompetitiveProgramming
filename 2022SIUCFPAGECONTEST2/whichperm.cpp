#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ifstream cin("whichpermi.txt");
  ofstream cout("whichpermo.txt");
  // Do 60 point way (nextperm brute force way)
  // Do 100 point writing your own recursive function with optimization
  int n;
  cin>> n;
  int d[n-1];
  for(int i=0; i<n-1; i++){
    cin>> d[i];
  }
  for

    return 0;
}
