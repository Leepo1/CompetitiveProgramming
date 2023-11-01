#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>

using namespace std;


int main(){
  int n,m;
  cin>> n >> m;
  
  set<pair<string,string> > s;

  for(int i=0; i<m; i++){
    pair<string,string> temp;
    cin>> temp.first >> temp.second;
    s.insert(temp);
  }
  if(s.size()==n){
    cout<< "YES";
  }else{
    cout<< "NO";
  }
 
  return 0;
}
