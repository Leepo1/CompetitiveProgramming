#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
using namespace std;
map<long long,long long> m;
set<long long> se;
int main(){

  //ifstream cin("pairup.in");
  //ofstream cout("pairup.out");
  vector<long long> v;
  long long n;
  cin>> n;

  for(int i=0; i<n; i++){
    long long c,s;
    cin >> c >> s;
    m[s]+=c;
    if(se.find(s)==se.end()){
      v.push_back(s);
    }
  }
  sort(v.begin(),v.end());
  long long answer=0;
  int l=0;
  int r=v.size()-1;


  while(l<r){
    int tl=l;
    int tr=r;
    answer=max(v[l]+v[r],answer);
    long long temp= min(m[v[l]],m[v[r]]);
    m[v[l]]-=temp;
    m[v[r]]-=temp;
    if(m[v[tl]]<=m[v[tr]]){

      l++;
    }
    if(m[v[tr]]<=m[v[tl]]){
      r--;
    }


}
  cout << answer;

  return 0;
}
