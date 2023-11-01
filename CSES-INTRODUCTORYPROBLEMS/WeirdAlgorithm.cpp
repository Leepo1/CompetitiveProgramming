#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(){
  //ifstream cin("WeirdAlgorithmi.txt");
  //ofstream cout("WeirdAlgorithmo.txt");
  long long n;
  cin>> n;
  cout<< n << " ";
  while(true){
    if(n==1){
      break;
    }
    if(n%2==1){
     n= 3*n+1;
     cout<< n << " ";
   }else{
     n/=2;
     cout<< n << " ";
   }
  }

  return 0;
}
