#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;


int main(){
  //ifstream cin("ScoreHackeri.txt");
  //ofstream cout("ScoreHackero.txt");

  ll n,k;
  cin>> n >> k;
  ll arr[n];
  ll avail=0;
  vector<ll> consider;
  ll medi= (n+1)/2;
  for(int i=0; i<n; i++){
    cin>> arr[i];
  }
  sort(arr,arr+n);
  for(int i=0; i<n; i++){
    if(i<medi-1){
      avail+=arr[i];
    }else{
      consider.push_back(arr[i]);
    }
  }

  if(k-avail<0){
    avail=k/2;
  }else{
    avail=k-avail;
  }

  ll L=consider[0];
  ll R= consider[consider.size()-1]+avail;
  ll answer=consider[0];


  while(L<=R){
    ll t=avail;
    bool works=false;
    ll M= L + (R-L)/2;

    for(int i=0; i<consider.size(); i++){
      if(consider[i]<M){
        if(t>=M-consider[i]){
          t-= (M-consider[i]);
          continue;
        }else{
          break;
        }
      }else{
        works=true;
        break;
      }
    }

    if(works){
      L=M+1;
      answer=M;
    }else{
      R=M-1;
    }

  }
  /*
  while(avail!=0){
      for(int i=0; i<consider.size(); i++){
        if(i==consider.size()-1){
          consider[i]++;
          avail--;
          break;
        }else{
          if(consider[i]+1<=consider[i+1]){
            consider[i]++;
            avail--;
            break;
          }
        }
      }
  }
  */
  cout<< answer << '\n';

    return 0;
}
