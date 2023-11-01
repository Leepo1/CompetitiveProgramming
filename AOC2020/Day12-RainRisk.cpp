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


int main(){
  ifstream cin("Day12-RainRiski.txt");
  ofstream cout("Day12-RainRisko.txt");
  string s;
  map<char,char> left;
  left['E']='N';
  left['N']='W';
  left['W']='S';
  left['S']='E';
  map<char,char> right;
  right['E']='S';
  right['S']='W';
  right['W']='N';
  right['N']='E';
  vector<int> numbers;
  vector<char> direction;
  while(cin>> s){
    direction.push_back(s[0]);
    numbers.push_back(stoi(s.substr(1,s.size()-1)));
  }
  int x=0;
  int y=0;
  int vx=10;
  int vy=1;

  for(int i=0; i<direction.size(); i++){
    if(direction[i]=='N'){
      vy+= numbers[i];
    }else if(direction[i]=='S'){
      vy-= numbers[i];
    }else if(direction[i]=='W'){
      vx-= numbers[i];
    }else if(direction[i]=='E'){
      vx+= numbers[i];
    }else if(direction[i]=='L'){
      int times=numbers[i]/90;
      int og=vx;
      if(times==1){
        vx= -1*vy;
        vy= og;
      }else if(times==2){
        vx= -1*vx;
        vy=-1*vy;
      }else if(times==3){
        vx= vy;
        vy= -1*og;
      }

    }else if(direction[i]=='R'){
      int times= numbers[i]/90;
      int og=vx;
      if(times==1){
        vx= vy;
        vy= -1*og;
      }else if(times==2){
        vx = -1*vx;
        vy= -1*vy;
      }else if(times==3){
        vx = -1*vy;
        vy= og;
      }

    }else if(direction[i]=='F'){
      x+=numbers[i]*vx;
      y+=numbers[i]*vy;
  }
}
  cout<< abs(x) +abs(y)<<'\n';
  cout<< "yo nigga" << '\n';
    return 0;
}
