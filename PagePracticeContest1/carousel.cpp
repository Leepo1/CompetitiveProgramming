#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
  //ifstream cin("carouseli.txt");
  //ofstream cout("carouselo.txt");
  long long c;
  cin>> c;

  while(c--){
    long long s, n, d;
    cin>> s >> n >> d;
    d%=n;
    if(s+d>n){
      cout<< d-(n-s) << '\n';
    }else{
      cout<< (s+d) << '\n';
    }
  }

  return 0;
}
