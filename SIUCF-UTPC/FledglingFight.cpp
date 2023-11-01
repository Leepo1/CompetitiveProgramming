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

int n;
vector<int> adj[200005];
bool visited[200005];
long long odd,even;


void adil(int x, int loc){

  if(visited[x]){
    return;
  }
  if(loc%2){
    odd++;
  }else{
    even++;
  }

  visited[x] =  true;
  for(int u:adj[x]){
    if(visited[u]) continue;
    adil(u, (loc+1)%2);
  }
}

int main(){
  //ifstream cin("FledglingFlighti.txt");
  //ofstream cout("FledglingFlighto.txt");
  odd = 0;
  even = 0;
  cin>>n;

  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }



  for(int i=0;i<=n; i++){
    visited[i] = false;
  }
  visited[0] = true;
  adil(1,0);

  cout<<(odd*(odd-1)) + (even*(even-1));



    return 0;
}
