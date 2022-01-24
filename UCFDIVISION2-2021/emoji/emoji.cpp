#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
using namespace std;




int main(){
//  ifstream cin("emoji.in");
//  ofstream cout("emoji.out");
  int t;
  cin >>t;
string s;
  for(int i=0; i<t; i++){
map<char,int> m;
cin>> s;
for(int j=0; j<s.size(); j++){
  if(m[s[j]]>0){
  cout<< "Nope" <<endl;
  break;
} else {
  m[s[j]]=1;

}
if(j==s.size()-1){
  cout<< "Emote away!" << endl;
}

  }

}
  return 0;
}
