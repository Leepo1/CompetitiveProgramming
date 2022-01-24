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
  ifstream cin("AdventofCodeDay3.in");
  ofstream cout("AdventofCodeDay3.out");
  string s;
  vector<string> v;
  vector<string> oxy;
  vector<string> carb;
  int carbin;
  int oxygen;
  while(cin>>s){
    oxy.push_back(s);
  }
  for(int i=0; i<oxy.size(); i++){
    carb.push_back(oxy[i]);

  }

  for(int i=0; i<s.size(); i++){
    if(carb.size()==1){
      break;
    }
    int onecount=0;
    int zerocount=0;
    for(int j=carb.size()-1; j>=0; j--){
      if(carb[j][i]=='1'){
        onecount=onecount+1;
      }else{
        zerocount=zerocount+1;
      }
    }
    if(onecount<zerocount){
      for(int g=carb.size()-1; g>=0; g--){
        if(carb[g][i]=='1'){
          carb.erase(carb.begin()+g);
        }
      }
    }else {
        for(int g=carb.size()-1; g>=0; g--){
          if(carb[g][i]=='0'){
            carb.erase(carb.begin()+g);
          }
        }
    }
  }
  carbin=stoi(carb[0],0,2);


for(int i=0; i<s.size(); i++){
  if(oxy.size()==1){
    break;
  }
  int onecount1=0;
  int zerocount2=0;
  for(int j=oxy.size()-1; j>=0; j--){
    if(oxy[j][i]=='1'){
      onecount1=onecount1+1;
    }else{
      zerocount2=zerocount2+1;
    }
  }

  if(onecount1<zerocount2){
    for(int g=oxy.size()-1; g>=0; g--){
      if(oxy[g][i]=='0'){
        oxy.erase(oxy.begin()+g);
      }
    }
  }else {
      for(int g=oxy.size()-1; g>=0; g--){
        if(oxy[g][i]=='1'){
          oxy.erase(oxy.begin()+g);
        }
      }
    }
}
oxygen=stoi(oxy[0],0,2);
cout<< carbin*oxygen;
    return 0;

}
