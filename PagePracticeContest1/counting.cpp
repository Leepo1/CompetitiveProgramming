#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <cmath>
#define ll long long
using namespace std;


int main(){
  //ifstream cin("countingi.txt");
  //ofstream cout("countingo.txt");

  int c;
  cin>> c;
  while(c--){

    vector<unsigned long long> v;

    unsigned long long n,s;

    cin >> n >> s;

    v.push_back(1);

    v.push_back(s);

    for(int i=1; i<=18; i++){
      unsigned long long a= 10*v[i];
      v.push_back(a);
      if(a>n){
        break;
      }
    }

    unsigned long long ans=0;

    for(auto it=v.end()-1; it>=v.begin(); it--){
      if(n>=*it){
        ans+= n/(*it);
        n%=(*it);
      }
    }


   cout<< ans << '\n';
  }
  return 0;
}
