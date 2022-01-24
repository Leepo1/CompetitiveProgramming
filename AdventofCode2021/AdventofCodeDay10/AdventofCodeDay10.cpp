#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <stdlib.h>
#include <utility>
#include <stack>
using namespace std;

int main(){

ifstream cin("AdventofCodeDay10.in");
ofstream cout("AdventofCodeDay10.out");
string s;
vector<long long> v;

map<char,int> m;
m['(']=1;
m['[']=2;
m['{']=3;
m['<']=4;
for(int i=1; i<=110; i++){
  bool a=false;
  long long score=0;
  stack<char> stackthing;
  cin>> s;
  for(int j=0; j<s.size(); j++){
    if(s[j]=='(' || s[j]=='[' || s[j]=='{' || s[j]=='<'){
    stackthing.push(s[j]);
  }
   else{
    if(s[j]==')' && stackthing.top()!='('){
      a=false;
      break;
    } else if(s[j]==']' && (stackthing.empty() || stackthing.top()!='[')){
      a=false;
      break;
    }else if(s[j]=='}' && stackthing.top()!='{'){
      a=false;
      break;
    }else if(s[j]=='>' && stackthing.top()!='<'){
      a=false;
      break;
    }
    stackthing.pop();
  }
  a=true;
  }

  if(a){
  while(true){
    if(!stackthing.empty()){
      score=score*5+m[stackthing.top()];
      stackthing.pop();
    }else{
      break;
    }
  }
    v.push_back(score);
}
}
sort(v.begin(),v.end());
long long vsize=v.size();
cout<< v[vsize/2];
    return 0;
  }
