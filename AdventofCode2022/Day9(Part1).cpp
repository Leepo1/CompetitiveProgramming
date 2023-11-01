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
set<ii> points;
map<char,int> m;


int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
ii knots[10];
ii distance(ii head, ii tail){
  return {head.first-tail.first, head.second-tail.second};
}
void move(ii head, ii tail, int k){
  ii diff = distance(head,tail);
  if(abs(diff.first)+abs(diff.second)==2){
    if(tail.first!=head.first && tail.second!=head.second){
      return;
    }
    tail.first+= diff.first/2;
    tail.second+= diff.second/2;
  }else if(abs(diff.first)+abs(diff.second)==3){
    tail.first += round((double)diff.first/2);
    tail.second += round((double)diff.second/2);
  }else if(abs(diff.first)+abs(diff.second)==4){
    tail.first+=diff.first/2;
    tail.second+=diff.second/2;
  }
  knots[k]=tail;
}
int main(){
  m['U']=0;
  m['D']=1;
  m['R']=2;
  m['L']=3;
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("Day9i.txt");
  //ofstream cout("Day9o.txt");


  for(int i=0; i<10; i++){
    knots[i]= {0,0};
  }

  points.insert({0,0});
  char s;

  while(cin>> s){
    int dir= m[s];
    int number; cin>> number;
    for(int i=0; i<number; i++){
      knots[0].first += dx[dir];
      knots[0].second += dy[dir];
      for(int k=1; k<10; k++){
        move(knots[k-1],knots[k],k);
        cout<< knots[k-1].first << " " << knots[k-1].second << " " << knots[k].first<< " " << knots[k].second << '\n';
      }

      points.insert(knots[9]);
}

  }
  cout<< points.size() << '\n';

    return 0;
}
