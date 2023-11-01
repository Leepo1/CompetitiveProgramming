#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main(){
  //ifstream cin("breedflip.in");
  //ofstream cout("breedflip.out");
  int n;
  cin>> n;
  string a,b;
  cin>> a >> b;
  int l=a.size();
  int answer=0;
  bool thing=false;
  for(int i=0; i<l; i++){
    if(a[i]!=b[i]){
      if(thing){
        continue;
      }else{
        answer++;
        thing=true;
      }
    }else{
      if(thing){
        thing=false;
      }else{
        continue;
      }
    }
  }
  cout<< answer << '\n';

  return 0;
}
