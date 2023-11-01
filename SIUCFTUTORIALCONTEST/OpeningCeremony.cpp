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
  ifstream cin("OpeningCeremonyi.txt");
  ofstream cout("OpeningCeremonyo.txt");
  int n;
  cin>> n;
  vector<int> v;

  for(int i=0; i<n; i++){
    int a;
    cin>> a;
    v.push_back(a);
  }
  sort(v.begin(),v.end());
  int op=0;
  while(true){
    if(v.size()==0){
      break;
    }
    if(v[v.size()-1]>=v.size()){
      op++;
      v.pop_back();
    }else{
      int index= lower_bound(v.begin(),v.end(),1)-v.begin()-1;
      for(int i=0; i<index; i++){
        v.erase(v.begin(),v.begin()+i);
        op++;
      }
    }
  }
  cout<< op;

    return 0;
}
