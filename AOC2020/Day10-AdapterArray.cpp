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
  ifstream cin("Day10-AdapterArrayi.txt");
  ofstream cout("Day10-AdapterArrayo.txt");
  
  vector<int> adapters;
  set<int> check;
  int x;

  while(cin>> x){
    check.insert(x);
    adapters.push_back(x);
  }

  sort(adapters.begin(),adapters.end());
  reverse(adapters.begin(),adapters.end());
  
  int m = adapters[0];
  check.insert(0);
  long long dp[m+1];

  for(int i=0; i<=m; i++){
    dp[i]=0;
  }

  dp[m]=1;
  
  for(int i=0; i<adapters.size(); i++){
    for(int j=1; j<=3; j++){
      int value= adapters[i]-j;
      if(value<0){
        break;
      }
      if(check.find(value)==check.end()){
        continue;
      }
      dp[value]+=dp[adapters[i]];
    }
  }

  cout<< dp[0];
    return 0;
}
