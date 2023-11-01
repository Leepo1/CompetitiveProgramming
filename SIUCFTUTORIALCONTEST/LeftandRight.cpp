#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <iomanip>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int n;
bool visited[1000000];
string order;

void perm(int n, vector<int> p, bool visited[n]){
  if(p.size()==n){
    for(int i=0; i<n; i++){
      cout<< p[i]+1;
    }
    cout<< endl;
    return;
  }

  for(int i=0; i<n; i++){
    if(visited[i]) continue;

    if(p.empty()){
      p.push_back(i);
      continue;
    }/*
    else{
      if(i<p[p.size()-1] && order[i]!='L'){
        continue;
      }
      if(i>p[p.size()-1] && order[i]!='R'){
        continue;
      }
    }
    */
    p.push_back(i);
    visited[i]=true;
    perm(n,p,visited);
    p.pop_back();
    visited[i]=false;
  }
}

int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  cout.tie(0);
  ifstream cin("LeftandRighti.txt");
  ofstream cout("LeftandRighto.txt");
  vector<int> p;
  cin>> n;
  cin>> order;
  for(int i=0; i<n; i++){
    visited[i]=false;
  }
  perm(n,p,visited);


    return 0;
}
