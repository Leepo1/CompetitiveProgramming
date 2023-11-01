#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
  //ifstream cin("threadi.txt");
  //ofstream cout("threado.txt");
  int c;
  cin>> c;
  while(c--){
    long double x,y;
    cin>> x >>y;
    long double answer= sqrt((x+sqrt(x*y))*(x+sqrt(x*y))+(y+sqrt(x*y))*(y+sqrt(x*y)));
    cout<< fixed << setprecision(7) << answer << '\n';
  }



  return 0;
}
