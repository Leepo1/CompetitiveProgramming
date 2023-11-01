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

set<ii> allrocks;

int highestrock=0;

map<char,int> wind;


int dy[2] = {1,-1};

set<ii> rock(ii leftedge, int type){
  set<ii> temp;
  if(type==0){
    temp.insert(leftedge);
    leftedge.second++;
    temp.insert(leftedge);
    leftedge.second++;
    temp.insert(leftedge);
    leftedge.second++;
    temp.insert(leftedge);
  }else if(type==1){
    temp.insert(leftedge);
    leftedge.second++;
    temp.insert(leftedge);
    leftedge.first--;
    temp.insert(leftedge);
    leftedge.first++; leftedge.second++;
    temp.insert(leftedge);
    leftedge.first++; leftedge.second--;
    temp.insert(leftedge);
  }else if(type==2){
    temp.insert(leftedge);
    leftedge.second++;
    temp.insert(leftedge);
    leftedge.second++;
    temp.insert(leftedge);
    leftedge.first++;
    temp.insert(leftedge);
    leftedge.first++;
    temp.insert(leftedge);
  }else if(type==3){
    temp.insert(leftedge);
    leftedge.second++;
    temp.insert(leftedge);
    leftedge.second++;
    temp.insert(leftedge);
    leftedge.second++;
    temp.insert(leftedge);
  }else if(type==4){
    temp.insert(leftedge);
    leftedge.second++;
    temp.insert(leftedge);
    leftedge.first++;
    temp.insert(leftedge);
    leftedge.second--;
    temp.insert(leftedge);
  }
  return temp;
}

set<ii> works(set<ii> rock, char dir){
  set<ii> temp;
  bool allwork=true;
  for(auto it : rock){
    it.second+=dy[wind[dir]];
    if(allrocks.find(it)!=allrocks.end() || it.second>=7 || it.second<0){
      allwork=false;
      break;
    }
  }
  if(!allwork) return temp;
  for(auto it : rock){
    it.second += dy[wind[dir]];
    temp.insert(it);
  }
  return temp;
}

void addtoall(set<ii> rock){
  for(auto it : rock){
    allrocks.insert(it);
    highestrock = max(highestrock, it.second);
  }
}

set<ii> movedown(set<ii> rock){
  set<ii> temp;
  for(auto it : rock){
    it.first--;
    temp.insert(it);
  }
  return temp;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("Day17i.txt");
  ofstream cout("Day17o.txt");

  string instructions; cin>> instructions;
  wind['>']=0;
  wind['<']=1;

  int spot=0;

  for(int r=0; r<2022; r++){
    ii leftedge; leftedge.first = highestrock+3; leftedge.second=2;
    set<ii> currentrock = rock(leftedge, r%5);

    for(int i=spot; i<instructions.size(); i++){
      set<ii> temp;
      temp = works(currentrock,instructions[i]);

      if(temp.size()!=0) currentrock=temp;
      for(auto it : currentrock){
        cout<< it.first << " " << it.second << '\n';
      }
      cout<< '\n';
      temp.clear();
      bool down=true;
      for(auto it : currentrock){
        it.first--;
        if(allrocks.find(it)!=allrocks.end() || it.first<0){
          down=false;
          break;
        }
        temp.insert(it);
      }
      spot++;
      if(down) currentrock=temp;
      if(!down) break;
    }

    addtoall(currentrock);
  }
  cout<< highestrock << '\n';
    return 0;
}
