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
vector<string> grid;
ii currpos;
int d=0;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int mod(int a, int base){
  while(a<0){
    a+=base;
  }
  return a%base;
}
string a = "                                                  ";
void action(string instruction){
  bool changedir=false;
  if(instruction=="L" || instruction=="R") changedir=true;
  if(instruction=="L") d-=1;
  if(instruction=="R") d+=1;
  d = mod(d,4);
  if(changedir) return;
  int number = stoi(instruction);
  for(int dist=0; dist<number; dist++){
    int nx = currpos.first + dx[d];
    int ny = currpos.second + dy[d];
    if(grid[nx][ny]=='u' || nx>=200 || ny>=150 || nx<0 || ny<0){
      if(d==0){
        for(int i=0; i<150; i++){
          if(grid[nx][i]!='u'){
            ny=i;
            break;
          }
        }
      }else if(d==1){
        for(int i=0; i<200; i++){
          if(grid[i][ny]!='u'){
            nx=i;
            break;
          }
        }
      }else if(d==2){
        for(int i=149; i>=0; i--){
          if(grid[nx][i]!='u'){
            ny=i;
            break;
          }
        }
      }else if(d==3){
        for(int i=199; i>=0; i--){
          if(grid[i][ny]!='u'){
            nx=i;
            break;
          }
        }
      }
    }
    if(grid[nx][ny]=='#') return;
    currpos.first=nx;
    currpos.second=ny;
  }
}
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("Day22i.txt");
  //ofstream cout("Day22o.txt");
  currpos.first=0; currpos.second=0;
  string s;
  int columns=150;
  for(int i=0; i<a.size(); i++){
    a[i]='u';
  }
  cout<< a.size() << '\n';
  for(int i=0; i<200; i++){
    getline(cin,s);

    if(i<100){
      string temp = a;
      temp+=s;
      s=temp;
    }
    int thing = s.size();
    for(int j=0; j<columns-thing; j++){
      s+='u';
    }
    grid.push_back(s);
  }


  vector<string> instructions;
  while(cin>>s){
    instructions.push_back(s);
  }
  for(auto u : instructions){
    action(u);
  }
  cout<< 1000*(currpos.first+1) << " " << 4*(currpos.second+1)  << " " << d;
    return 0;
}
