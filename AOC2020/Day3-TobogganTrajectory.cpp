#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <stack>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;


int main(){
  ifstream cin("Day3-TobogganTrajectoryi.txt");
  ofstream cout("Day3-TobogganTrajectoryo.txt");
  vector<string> v;
  string s;
  int count=0;

  vector<int> nums;
  while(cin>> s){
    v.push_back(s);
    count++;
  }

  int x=0;
  int y=0;

  int tree=0;
  if(v[x][y]=='#') tree++;
  while(x<count){
    x+=1;
    y+=3;
    if(v[x][y%v[0].size()]=='#') tree++;
  }
  nums.push_back(tree);

  x=0;
  y=0;

  tree=0;
  if(v[x][y]=='#') tree++;
  while(x<count){
    x+=1;
    y+=1;
    if(v[x][y%v[0].size()]=='#') tree++;
  }
  nums.push_back(tree);

  x=0;
  y=0;

  tree=0;
  if(v[x][y]=='#') tree++;
  while(x<count){
    x+=1;
    y+=5;
    if(v[x][y%v[0].size()]=='#') tree++;
  }
  nums.push_back(tree);

  x=0;
  y=0;

  tree=0;
  if(v[x][y]=='#') tree++;
  while(x<count){
    x+=1;
    y+=7;
    if(v[x][y%v[0].size()]=='#') tree++;
  }
  nums.push_back(tree);

  x=0;
  y=0;

  tree=0;
  if(v[x][y]=='#') tree++;
  while(x<count){
    x+=2;
    y+=1;
    if(v[x][y%v[0].size()]=='#') tree++;
  }
  nums.push_back(tree);
  ll prod=1;
  for(int i=0; i<nums.size(); i++){
    prod*=nums[i];
  }
  cout<< prod << '\n';
    return 0;
}
