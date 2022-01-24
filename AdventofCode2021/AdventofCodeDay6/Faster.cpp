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

int main(){
  ifstream cin("AdventofCodeDay6.in");
  ofstream cout("AdventofCodeDay6.out");
  vector<int> v;
  int x;
  char c;
  while(cin>>x){
    v.push_back(x);
    cin>> c;
  }

long long totalcount=v.size();
  for(int q=1; q<=256; q++){
  for(int i=0; i<v.size(); i++){
      if(v[i]==0){
      totalcount=totalcount+((256-q)/7));
      newcount=newcount+1;
      }else{
        v[i]=v[i]-1;
      }
  }
  for(int i=v.size()-1; i>=0; i--){
    if(v[i]==0){
      v.erase(v.begin()+i);
    }
  }
  for(int i=0; i<newcount; i++){
    v.push_back(8);
  }

}
cout<< v.size();

    return 0;
}
