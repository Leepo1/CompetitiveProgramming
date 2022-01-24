#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main(){
  ifstream cin("arithmetic.in");
  ofstream cout("arithmetic.out");
  int t;
  cin>> t;
for(int q=0; q<t; q++){
    int x,n,n2;
    cin>> x>>n;
    if(x%2==1){
      if(n%x!=0){
        cout<< "IMPOSSIBLE";
      } else{
        for(int i=0; i<x; i++){
          cout<< n/x+((i+1)-(x/2+1))*(n/x-1) << " ";
        }
      }
      if(q!=(t-1)){
      cout<< endl;
    }
    } else{
        if(n%(x/2)!=0){
          cout<< "IMPOSSIBLE";
        }else {
          n2=n/(x/2);
          if(n2%2==1){
            for(int i=0; i<x; i++){
            cout<< (n2-1)/2+(i+1-(x/2)) << " ";
            }
          }else {
          for(int i=0; i<x; i++){
            cout<< n/x << " ";
          }
}
        }
        if(q!=(t-1)){
        cout<< endl;
      }
}

    }
    return 0;

}
