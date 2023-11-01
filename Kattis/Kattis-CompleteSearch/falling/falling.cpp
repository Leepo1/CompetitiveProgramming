#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

vector<int> lowerfactors;
void putlowerfactors(double x){
  for(int i=1; i<=sqrt(x); i++){
    if((int)x%i==0){
      lowerfactors.push_back(i);
    }
  }
}
int main(){


  //ifstream cin("fallingi.txt");
  //ofstream cout("fallingo.txt");

  double n;
  cin>> n;
  putlowerfactors(n);
  int number= n;
  int x,y;
  for(int i=0; i<lowerfactors.size(); i++){
    if((lowerfactors[i]+number/lowerfactors[i])%2==0){
      x=(lowerfactors[i]+number/lowerfactors[i])/2;
      y=x-lowerfactors[i];
      if(y>=0 && x>=0){
        cout<< y << " " << x;
        return 0;
      }
    }
  }
  cout<< "impossible";









  return 0;
}
