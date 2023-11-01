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
#include <sstream>
#include <stack>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
bool seat[128][8];
void eval(string s){
  string row= s.substr(0,7);
  string column= s.substr(7,3);
  int L=0,R=127;

  for(int i=0; i<row.size(); i++){
    double temp = (L+R)/2.0;
    if(row[i]=='F'){
      R= floor(temp);
    }else{
      L=ceil(temp);
    }
  }

  int rn=L;
  L=0,R=7;
  for(int i=0; i<column.size(); i++){
    double temp= (L+R)/2.0;
    if(column[i]=='L'){
      R= floor(temp);
    }else{
      L= ceil(temp);
    }
  }
  int cn=L;
  seat[rn][cn]=true;
}
int main(){
  ifstream cin("Day5-BinaryBoardingi.txt");
  ofstream cout("Day5-BinaryBoardingo.txt");
  string s;
  for(int i=0; i<128; i++){
    for(int j=0; j<8; j++){
      seat[i][j]=false;
    }
  }
  while(cin>> s){
    eval(s);
  }

  for(int i=0; i<128; i++){
    for(int j=0; j<8; j++){
      if(!seat[i][j] && i!=0 && i!=127){
        cout<< i*8+j << '\n';
        break;
      }
    }
  }
     return 0;
}
