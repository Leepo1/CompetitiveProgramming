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
  ifstream cin("carniceroi.txt");
  ofstream cout("carniceroo.txt");
  int c;
  cin>> c;
  while(c--){
    int n;
    cin>> n;
    if(n==1){
      int start,end, amount;
      cin>> start >> end >> amount;
      double answer= (double)amount/(end-start);
      cout<< answer << '\n';
      continue;
    }else{
      int start[2];
      int end[2];
      int amount[2];
      for(int i=0; i<2; i++){
        cin >> start[i] >> end[i] >> amount[i];
      }
      if(){

      }

    }

  }

    return 0;
}
