#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <iomanip>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  //ifstream cin("speedi.txt");
  //ofstream cout("speedo.txt");
  int n;
  int t;
  cin >> n >>t;

  long double d[n];
  long double s[n];
  long double c;
  for(int i=0; i<n; i++){
    cin>> d[i] >> s[i];
    if(i==0){
      c= s[0];
    }else{
      c= min(s[i],c);
    }
  }

  c= (-1)*c;

  long double L=c+.0000000001,R=1000000000, final;

  for(int j=0; j<600; j++){
    long double M= L + (R-L)/2;
    long double time=0;
    for(int i=0; i<n; i++){
      time+= d[i]/(s[i]+M);
    }
    // THIS PART
    if(t==time){
      final=M;
      break;
    }
    // OMG
    if(t>time){
      R=M;
      final=M;
    }else{
      L=M;
      final=M;
    }
  }
  cout<< fixed << setprecision(9) <<  final << '\n';
    return 0;
}
