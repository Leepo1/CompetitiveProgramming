#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  string s;
  cin>> s;
  int m=1;
  int current=1;
  for(int i=0; i<s.size(); i++){
    if(i==0) continue;
    if(s[i]==s[i-1]){
      current+=1;
      m= max(m,current);
    }else{
      current=1;
    }
  }
  cout<< m;
  return 0;
}
