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

map<long long,long long> space;
int main(){

  ios_base::sync_with_stdio(0);
	cin.tie(0);
  cout.tie(0);

  //ifstream cin("dinosauri.txt");
  //ofstream cout("dinosauro.txt");

  int c;
  cin>> c;

  while(c--){
    space.clear();
    long long n,m;
    cin>> n >> m;
    vector<long long> v;
    long long money=0;
    for(int i=0; i<n; i++){
      string s; cin>> s;
      long long a, number;
      cin>> a >> number;
      long long income,cost;
      cin>> income >> cost;
      long long profit=(income-cost);
      long long add= a*number;
      space[profit]+= add;
      v.push_back(profit);
    }
    sort(v.begin(),v.end());

    for(int i=v.size()-1; i>=0; i--){
      if(v[i]>0){
        if(space[v[i]]<=m){
          m-=space[v[i]];
          money+= v[i]*space[v[i]];
        }else{
          money+= v[i]*m;
          break;
        }
      }
    }
   cout<< "$" << money << '\n';
  }

    return 0;
}
