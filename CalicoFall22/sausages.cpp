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
  ifstream cin("sausagesi.txt");
  ofstream cout("sausageso.txt");
  int tc; cin>> tc;
  while(tc--){
    int n; cin>> n;
    long long k; cin>> k;
    int top[n];
    int bot[n];
    int topest=1;
    int lowest=10000;
    for(int i=0; i<n; i++){
      cin>> top[i];
      topest=max(topest,top[i]);
    }
    for(int i=0; i<n; i++){
      cin>> bot[i];
      lowest= min(lowest,bot[i]);
    }

    bool works=false;

    for(int i=topest; i>=lowest; i--){
      if(i==lowest) break;
      int L=lowest,R=i-1;
      int answer;
      while(L<R){
        int M= L + (R-L)/2;
        long long amount=0;
        for(int g=0; g<n; g++){
          if(top[g]<=M) continue;
          if(bot[g]>=i) continue;
          int t = min(top[g],i);
          int b = max(bot[g],M);
          amount += t-b;
      }
      if(amount==k){
        answer=M;
        works=true;
        break;
      }
      if(amount<k){
        R=M-1;
      }
      if(amount>k){
        L=M+1;
      }
    }
    if(works){
      cout<< answer << " " << i << '\n';
      break;
    }
  }

    if(!works) cout<< "IMPOSSIBLE" << '\n';
  }




    return 0;
}
