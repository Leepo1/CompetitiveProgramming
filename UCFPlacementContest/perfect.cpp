#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <fstream>
#include <cmath>
using namespace std;

double distance( double a, double b , double c , double d){
  return sqrt(abs((d-b))*abs((d-b))+abs((c-a))*abs((c-a)));
}

int main(){
  //ifstream cin("perfecti.txt");
  //ofstream cout("perfecto.txt");
  long long t;
  cin>> t;

  while(t--){
    long long n;
    cin>> n;
    map<double,double> m;
    double a,b;
    vector<double> x;

    for(long long i=0; i<n; i++){
      cin>> a >> b;
      m[a]=b;
      x.push_back(a);
    }

    sort(x.begin(),x.end());

    double d=0;
    d+=distance(0,0,x[0],m[x[0]]);


    for(long long i=0; i<n-1; i++){
      d+=distance(x[i],m[x[i]],x[i+1],m[x[i+1]]);

    }
    cout<< fixed << setprecision(7) << d << '\n';
  }

  return 0;
}
