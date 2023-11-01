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

vector<ll> all;
// 133015568

int main(){

  ifstream cin("Day9-EncodingErrori.txt");
  ofstream cout("Day9-EncodingErroro.txt");
  ll x;

  while(cin>> x){
    all.push_back(x);
  }
  for(int size=2; size<=all.size(); size++){
    for(int i=0; i<all.size(); i++){
      ll currmin=all[i];
      ll currmax=all[i];
      ll sum=all[i];
      for(int j=i+1; j<i+size; j++){
        if(all[j]<currmin) currmin=all[j];
        if(all[j]>currmax) currmax=all[j];
        sum+=all[j];
      }
      if(sum==133015568){
        cout<< currmin+currmax <<'\n';
        return 0;
      }
    }
  }

    return 0;
}
