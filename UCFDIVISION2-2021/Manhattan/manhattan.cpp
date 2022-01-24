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
//  ifstream cin("manhattan.in");
//  ofstream cout("manhattan.out");
  int t;
  cin>>t ;
  int x,y;
  int w,z;
  for(int q=0; q<t; q++){
cin>> x>>y>>w>>z;
  if(x==w || y==z){
    cout<< "Dr. Manhattan wins again!" << endl;
  }else {
    cout<< "Euclid is too fast!" << endl;
  }


  }
    return 0;

}
