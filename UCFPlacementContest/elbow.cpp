#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;

  long double individual(int height, int armlength, long double tableheight , int width){
    long double a = sqrt((armlength)*(armlength)-(height-tableheight)*(height-tableheight));
  return width+2*a;
}

struct fri{
  int width;
  int height;
  int armlength;
};

int main(){
  //ifstream cin("elbowi.txt");
  ///ofstream cout("elbowo.txt");
  int c;
  cin>> c;
  while(c--){
    int n;
    cin>> n;
    long long l;
    cin >> l;
    fri f[n];
    long double high=0;
    long double low=0;
    for(int i=0; i<n; i++){
      cin>> f[i].width >> f[i].height >> f[i].armlength;
      if(f[i].height>high){
        high=f[i].height;
      }
      if((f[i].height-f[i].armlength)>low){
        low=f[i].height-f[i].armlength;
      }
    }
    // Binary Search on height

    long double L=low,R=high;
    long double M;
    for(int q=0; q<64; q++){
      M = L + (R-L)/2;
      long double local=0;
      for(int i=0; i<n; i++){
        local+= individual(f[i].height,f[i].armlength, M, f[i].width);
      }
    //  cout<< local << " "<< M << '\n';
    if(local>l){
      R=M;
      }else if(local<l){
        L=M;
      }
    }
    cout<< fixed << setprecision(20)<<  M << '\n';
  }
  return 0;
}
