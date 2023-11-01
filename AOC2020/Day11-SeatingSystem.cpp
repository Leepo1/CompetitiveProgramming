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

int dx[8]= {1,-1,0,0,1,1,-1,-1};
int dy[8]= {0,0,1,-1,-1,1,1,-1};

int main(){
  ifstream cin("Day11-SeatingSystemi.txt");
  //ofstream cout("Day11-SeatingSystemo.txt");
  string x;
  vector<string> all;
  vector<string> next;
  while(cin>> x){
    all.push_back(x);
  }

while(true){
  for(int i=0; i<all.size(); i++){
    string l="";
    for(int j=0; j<all[i].size(); j++){
      int oc=0;
      char a= all[i][j];
      for(int d=0; d<8; d++){
        int currx= i;
        int curry=j;

        while(true){
          int nx= currx+dx[d];
          int ny= curry+dy[d];

          if(nx>=0 && ny>=0 && nx<all.size() && ny<all[i].size()){
            if(all[nx][ny]=='L'){
              break;
            }
            if(all[nx][ny]=='#'){
              oc++;
              break;
            }
          }else{
            break;
          }
          currx=nx;
          curry=ny;
        }

      }

      if(a=='L' && oc==0){
        a='#';
      }else if(a=='#' && oc>=5){
        a='L';
      }
      l+=a;
    }
    next.push_back(l);
  }

  if(all==next){
    break;
  }
  all=next;
  next.clear();
}

  int count=0;
  for(int i=0; i<all.size(); i++){
    for(int j=0; j<all[i].size(); j++){

      if(all[i][j]=='#'){
        count++;
      }

    }

  }
  cout<< count << '\n';
    return 0;
}
