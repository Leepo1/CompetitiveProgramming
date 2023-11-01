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

  int n;

  vector<int> v;
  set<int> s;

  while(cin >> n){
    v.push_back(n);
    s.insert(n);
  }

  sort(v.begin(), v.end());

  for(int i=0; i<v.size(); i++){
    for(int j=i+1; j<v.size(); j++){
      if(s.find(2020-(v[i]+v[j]))!=s.end()){
        cout<< v[i]*v[j]*(2020-(v[i]+v[j]));
        return 0;
      }else {
        if(v[i]+v[j]>=2020){
          break;
        }
      }
    }
  }


    return 0;
}
