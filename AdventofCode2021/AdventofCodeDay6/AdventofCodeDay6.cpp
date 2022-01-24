#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
using namespace std;
map<int,long long> old;

int main(){
  ifstream cin("AdventofCodeDay6.in");
  ofstream cout("AdventofCodeDay6.out");
  vector<int> v;
  int x;
  char c;
  long long sum=0;

  while(cin>>x){
    old[x]=old[x]+1;
    cin>> c;
  }
  for(int q=0; q<256; q++){
    map<int, long long> extra;
    for(int i=0; i<9; i++){
      if(i==0){
        extra[6]=extra[6]+old[0];
        extra[8]=extra[8]+old[0];
      }else {
        extra[i-1]+=old[i];
      }
    }
    for(int i=0; i<9; i++){
      old[i]=extra[i];

    }

  }
  for(int i=0; i<9; i++){
    sum=sum+old[i];
  }

  cout<< sum;






    return 0;
}
