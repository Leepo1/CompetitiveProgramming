#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
using namespace std;
int factorial(int n){
  if(n==0){
    return 1;
  }
  return n*factorial(n-1);
}
int main(){
  //ifstream cin("wordi.txt");
  //ofstream cout("wordo.txt");
  int n;
  cin>> n;

  for(int i=0; i<n; i++){
    long long total=1;
    string s;
    cin>> s;
    int a= s.size();
    cout<< factorial(a) << '\n';
    }



  return 0;
}
