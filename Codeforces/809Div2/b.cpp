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


int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  cout.tie(0);
  //ifstream cin("bi.txt");
  //ofstream cout("bo.txt");
  int t;
  cin>> t;

  while(t--){
    bool inlist[100005];
    for(int i=1; i<=100000; i++){
      inlist[i]=false;
    }
    int n;
    cin>> n;
    int colors[n];
    vector<int> parity[n+1];


    for(int i=0; i<n; i++){
      cin>> colors[i];
      inlist[colors[i]]=true;
      if(i%2==0){
        parity[colors[i]].push_back(0);
      }else{
        parity[colors[i]].push_back(1);
      }
    }

    for(int i=1; i<=n; i++){
      int count=0;
      bool prev;
      for(int j=0; j<parity[i].size(); j++){
        if(j==0){
          count++;
          prev=parity[i][j];
          continue;
        }
        if(prev!=parity[i][j]){
          prev=parity[i][j];
          count++;
        }

      }
      cout<< count << " ";

    }
        cout<< '\n';
  }

    return 0;
}
