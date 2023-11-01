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
#include <sstream>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
int dx[12] = {-1,-1,-1,1,1,1,0,1,-1,0,1,-1};
int dy[12] = {0,1,-1,0,1,-1,-1,-1,-1,1,1,1};
bool stop=false;

int surroundingx[8] = {1,1,1,-1,-1,-1,0,0};
int surroundingy[8] = {1,-1,0,1,-1,0,1,-1};

set<ii> elves;

set<ii> update;
map<ii,ii> movie;
map<ii,int> c;
string s;
vector<string> grid;
int rounds=0;
int lowestx=1000;
int highestx=0;
int lowesty=1000;
int highesty=0;

ii check(int direction, ii test){
  //North
  if(direction==0){
    for(int d=0; d<3; d++){
      int nx = test.first + dx[d];
      int ny = test.second + dy[d];
      ii temp; temp.first = nx; temp.second=ny;
      if(elves.find(temp)!=elves.end()){
        return test;
      }
    }
    test.first--;
    return test;
  }
  //South
  if(direction==1){
    for(int d=3; d<6; d++){
      int nx = test.first + dx[d];
      int ny = test.second + dy[d];
      ii temp; temp.first = nx; temp.second=ny;
      if(elves.find(temp)!=elves.end()){
        return test;
      }
    }
    test.first++;
    return test;
  }
  //West
  if(direction==2){
    for(int d=6; d<9; d++){
      int nx = test.first + dx[d];
      int ny = test.second + dy[d];
      ii temp; temp.first = nx; temp.second=ny;
      if(elves.find(temp)!=elves.end()){
        return test;
      }
    }
    test.second--;
    return test;
  }
  //East
  if(direction==3){
    for(int d=9; d<12; d++){
      int nx = test.first + dx[d];
      int ny = test.second + dy[d];
      ii temp; temp.first = nx; temp.second=ny;
      if(elves.find(temp)!=elves.end()){
        return test;
      }
    }
    test.second++;
    return test;
  }

}

void bounds(ii test){
  if(test.first>highestx) highestx=test.first;
  if(test.first<lowestx) lowestx=test.first;
  if(test.second<lowesty) lowesty=test.second;
  if(test.second>highesty) highesty=test.second;
  return;
}

void firsthalfround(){
  for(auto it : elves){
    int any=0;
      for(int d=0; d<8; d++){
        int nx = it.first+ surroundingx[d];
        int ny = it.second+ surroundingy[d];
        ii temp; temp.first = nx; temp.second = ny;
        if(elves.find(temp)!=elves.end()) any++;
    }
    if(any==0){
      movie[it]=it;
      c[movie[it]]++;
      continue;
    }
    int count=1;
    int which=rounds;
    bool works=false;
    while(count<=4){
      which%=4;
      if(check(which, it)!=it){
        movie[it]=check(which,it);
        c[movie[it]]++;
        works=true;
        break;
      }
      which++;
      count++;
    }
    if(!works){
      movie[it]=it;
      c[movie[it]]++;
    }
  }
}

void secondhalfround(){
  bool moved=false;
  for(auto it : elves){
    if(c[movie[it]]>1){
      movie[it]=it;
    }
    ii n = movie[it];
    if(it!=movie[it]) moved=true;
    if(rounds==9) bounds(n);
    update.insert(n);
  }
  if(!moved) stop=true;
  elves = update;
  rounds++;
}

int number=0;
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("Day23i.txt");
  //  ofstream cout("Day23o.txt");

  while(getline(cin,s)){
    grid.push_back(s);
  }

  for(int i=0; i<grid.size(); i++){
    for(int j=0; j<grid[i].size(); j++){
      if(grid[i][j]=='#'){
        ii temp; temp.first=i; temp.second=j;
        elves.insert(temp);
        number++;
      }
    }
  }

  int t=10;
  while(true){
    update.clear();
    movie.clear();
    c.clear();
    firsthalfround();
    secondhalfround();
    if(stop) break;
  }
  cout<< rounds << '\n';
  cout<< highestx-lowestx << " " << highesty-lowesty <<  '\n';
  int area = (highestx-lowestx+1)*(highesty-lowesty+1)-number;
  cout<< area << '\n';
   return 0;
}
