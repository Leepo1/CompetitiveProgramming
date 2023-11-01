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


int main(){
  ifstream cin("Day1-ReportRepairi.txt");
  ofstream cout("Day1-ReportRepairo.txt");
  set<ll> s;
  ll n;
  while(cin>> n){
    if(s.find(2020-n)!=s.end()){
      cout<< n*(2020-n);
      break;
    }else{
      s.insert(n);
    }
  }

    return 0;
}
