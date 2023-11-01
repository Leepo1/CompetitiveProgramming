#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <map>
map<string, int> ID;
int main(){
  ifstream cin("ladderi.txt");
  ofstream cout("laddero.txt");
  int d,q,n;
  cin>> d >> q >> n;
  string s;

  for(int i=0; i<n; i++){
    cin>> s;
    ID[s]=i;
  }


  return 0;
}
