#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <set>
using namespace std;

int main(){
//  ifstream cin("DistinctNumbersi.txt");
//  ofstream cout("DistinctNumberso.txt");
  int n;
  cin>> n;
  int ans=0;
  set<int> s;
  for(int i=0; i<n; i++){
    int a;
    cin>> a;
    if(s.find(a) != s.end()){
      continue;
    }else{
      ans++;
      s.insert(a);
    }
  }
  cout<< ans;
  return 0;
}
