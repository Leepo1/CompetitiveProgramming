#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;
int jacob(int n){
  if(n%2==1){
    return n;
  }else {
    return jacob(n/2);
  }
}
int main(){
  //ifstream cin("jacobseqi.txt");
  //ofstream cout("jacobseqo.txt");
  int c;
  cin>> c;
  while(c--){
    int n;
    cin>> n;
    cout << jacob(n) << '\n';
  }


  return 0;
}
