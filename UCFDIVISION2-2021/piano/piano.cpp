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
  map<char,int> m;
  m['C']=1;
  m['D']=2;
  m['E']=3;
  m['F']=4;
  m['G']=5;
  m['A']=6;
  m['B']=7;

  ifstream cin("piano.in");
  ofstream cout("piano.out");
  int t;
  cin>>t;
  for(int q=0; q<t; q++){
    int l,r,x;
    string s;
    cin>> s;
    for(int i=0; i<s.size(); i++){
      int x=m[s[i]];
      if(i==0 && x!=7){
      l=x;
      r=x+1;
    }else if(i==0 && x==7){
      r=x;
      l=x-1;
    }
    if(x<=l){
      cout<< "L";
      l=x;
    }else if(x>=r){
      cout<< "R";
      r=x;
    }else {
      cout<< "L";
      l=x;
    }
    }
    cout<< endl;
  }

    return 0;

}
