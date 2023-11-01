#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
  //ifstream cin("scoringi.txt");
  //ofstream cout("scoringo.txt");
  int t;
  cin>> t;
  while(t--){
    int n, l, r;
    float floatcount=0;
    cin>> n >> l >> r;
    float number[n];

    for(int i=0; i<n; i++){
      cin>> number[i];
    }
    sort(number,number+n);
    for(int i=l; i<(n-r); i++){
      floatcount+=number[i];
    }
    cout<< fixed;
    cout << setprecision(7) << floatcount/(n-l-r)<< endl;
  }

  return 0;
}
