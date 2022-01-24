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
#include <set>
#include <stack>
using namespace std;
vector<pair<int, int> > v;
set<pair<int,int> > s;
void reflectx(int n){
  for(int i=0; i<v.size(); i++){
    if(v[i].first<n){
      s.insert(make_pair(v[i].first,v[i].second));
    } else if(v[i].first>n){
      s.insert(make_pair(n-(v[i].first-n), v[i].second));
    }
  }
}

void reflecty(int n){
  for(int i=0; i<v.size(); i++){
    if(v[i].second<n){
      s.insert(make_pair(v[i].first,v[i].second));
    } else if(v[i].second>n){
      s.insert(make_pair(v[i].first, n-(v[i].second-n)));
    }
  }
  }




int main(){

ifstream cin("AdventofCodeDay13.in");
ofstream cout("AdventofCodeDay13.out");
int a, b;
char c;
string useless;
while(cin>> a){
  cin>> c;
  cin>> b;
  v.push_back(make_pair(a,b));
}
getline(cin,useless);
reflectx(655);
v.clear();
auto it = s.begin();
while(it!=s.end()){
  v.push_back(*it);
}
s.clear();

reflecty(447);
v.clear();
auto it = s.begin();
while(it!=s.end()){
  v.push_back(*it);
}
s.clear();

reflectx(327);
v.clear();
auto it = s.begin();
while(it!=s.end()){
  v.push_back(*it);
}
s.clear();

reflecty(223);
v.clear();
auto it = s.begin();
while(it!=s.end()){
  v.push_back(*it);
}
s.clear();

reflectx(163);
v.clear();
auto it = s.begin();
while(it!=s.end()){
  v.push_back(*it);
}
s.clear();

reflecty(111);
v.clear();
auto it = s.begin();
while(it!=s.end()){
  v.push_back(*it);
}
s.clear();

reflectx(81);
v.clear();
auto it = s.begin();
while(it!=s.end()){
  v.push_back(*it);
}
s.clear();

reflecty(55);
v.clear();
auto it = s.begin();
while(it!=s.end()){
  v.push_back(*it);
}
s.clear();

reflectx(40);
v.clear();
auto it = s.begin();
while(it!=s.end()){
  v.push_back(*it);
}
s.clear();

reflecty(27);
v.clear();
auto it = s.begin();
while(it!=s.end()){
  v.push_back(*it);
}
s.clear();

reflecty(13);
v.clear();
auto it = s.begin();
while(it!=s.end()){
  v.push_back(*it);
}
s.clear();

reflecty(6);
v.clear();
auto it = s.begin();
while(it!=s.end()){
  v.push_back(*it);
}
s.clear();

cout<< s[(s.end()-1).first];




/*
fold along x=655
fold along y=447
fold along x=327
fold along y=223
fold along x=163
fold along y=111
fold along x=81
fold along y=55
fold along x=40
fold along y=27
fold along y=13
fold along y=6
*/
















    return 0;
  }
