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


vector<int> primes;

bool isprime(int a){
  if(a==1) return true;
  if(a==2) return true;
  if(a==3) return true;
  if(a%2==0) return false;
  if(a%3==0) return false;
  for(int i=5; i*i<= a; i+=2){
    if(a%i==0) return false;
  }
  return true;
}

int fj[5000005];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("CircularBarni.txt");
  ofstream cout("CircularBarno.txt");
  int t; cin>> t;
  fj[1]=2;
  primes.push_back(2);
  for(int i=1; i<=5000000; i+=2){
    if(isprime(i)){
      fj[i]=2;
      primes.push_back(i);
    }
  }
  for(int i=1; i<=5000000; i++){
    if(fj[i]==2) continue;
    bool winfound=false;
    for(auto u : primes){
      if(u>i) break;
      if(fj[i-u]>0){
        if(winfound){
          fj[i]= min(fj[i],fj[i-u]+1);
        }else{
          fj[i]=fj[i-u]+1;
          winfound=true;
        }
      }else{
        if(winfound) continue;
        fj[i]= fj[i-u]-1;
      }
    }
  }

  for(int i=1; i<=7; i++){
    cout<< fj[i] << " ";
  }

    return 0;
}
