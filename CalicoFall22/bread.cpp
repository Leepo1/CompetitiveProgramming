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
  ifstream cin("breadi.txt");
  ofstream cout("breado.txt");
  int t; cin>> t;
  while(t--){
    int n,c,d; cin>> n >> c >> d;
    int bread[n];
    vector<int> zeros;
    for(int i=0; i<n; i++){
      cin>> bread[i];
      if(bread[i]==0) zeros.push_back(i);
    }
    long long answer=0;
    long long prefix[n+1];
    prefix[0]=0;
    for(int i=1; i<=n; i++){
      prefix[i]=prefix[i-1]+bread[i-1];
    }

    int next=0;
    for(int i=next; i<n-d+1; i++){
      bool bet=false;
      for(int j=0; j<zeros.size(); j++){
        if(zeros[j]>i+d-1) break;
        if(zeros[j]<=i+d-1 && zeros[j]>=i){
          bet=true;
          next=zeros[j]+1;
          answer=max(prefix[zeros[j]]-prefix[max(zeros[j]-d,0)],answer);
          break;
        }
        if(bet) continue;
        answer= max(prefix[i+d]-prefix[i],answer);
        next++;
      }
    }
    
    cout << '\n';
  }

    return 0;
}
