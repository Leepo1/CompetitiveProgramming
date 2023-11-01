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
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("Day10i.txt");
  ofstream cout("Day10o.txt");
  string s;
  int x=1;
  int cycle=0;
  char grid[245];

  while(cin>> s){
    if(s=="noop"){
      int temp= cycle%40;

      if(temp>=x-1 && temp<=x+1){
        grid[cycle]='#';
        cycle++;
        continue;
      }else{
        grid[cycle]=' ';
        cycle++;
        continue;
      }
    }else{
      int temp =cycle%40;
      int k; cin>> k;
      if(temp>=x-1 && temp<=x+1){
        grid[cycle]='#';
        cycle++;
      }else{
        grid[cycle]=' ';
        cycle++;
      }
      temp=cycle%40;
      if(temp>=x-1 && temp<=x+1){
        grid[cycle]='#';
        cycle++;
      }else{
        grid[cycle]=' ';
        cycle++;
      }
        x+=k;
    }

  }
  for(int i=0; i<240; i++){
    cout<< grid[i];
    if(i==0) continue;
    if((i+1)%40==0) cout<< '\n';
  }
    return 0;
}
