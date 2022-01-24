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
#include<string.h>
#include <set>
using namespace std;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
map<string,vector<string> > v;
int answer=0;
set<string> visited;
map<string,int> m;
void check(string s){

if(s=="end"){
  answer=answer+1;
  return;
}
if(s[0]!=toupper(s[0]) && visited.count(s) && m[s]>2){
  return;
}else if(s[0]!=toupper(s[0])){
  visited.insert(s);
  if(m[s]==0){
  m[s]=m[s]+1;
}else if(m[s]==1){
  auto it = visited.begin();
  while(it!=visited.end()){
    if(m[*it]==2){
      return;
    }
    it++;
  }
  m[s]=m[s]+1;
}

}
for(int i=0; i<v[s].size(); i++){
  if(v[s][i]!="start"){
  check(v[s][i]);
}
}
if(s[0]!=toupper(s[0])){
  visited.erase(s);
  m[s]=m[s]-1;
}

}

int main(){

  ifstream cin("AdventofCodeDay12.in");
  ofstream cout("AdventofCodeDay12.out");
string s;
for(int i=0; i<22; i++){
cin>> s;
for(int j=0; j<s.size(); j++){
  if(s[j]=='-'){
    v[s.substr(0,j)].push_back(s.substr(j+1,s.size()-j-1));
    v[s.substr(j+1,s.size()-j-1)].push_back(s.substr(0,j));
  }
}
}




check("start");
cout<< answer;





return 0;
}
