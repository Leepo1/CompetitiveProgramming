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
  //ifstream cin("i.txt");
  //ofstream cout("o.txt");
  int t; cin>> t;
  while(t--){
    int n; cin>> n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int a; cin>> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    
  }

    return 0;
}
