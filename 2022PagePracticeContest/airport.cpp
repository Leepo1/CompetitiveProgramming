#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <set>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  //ifstream cin("airporti.txt");
  //ofstream cout("airporto.txt");
  int n,k;
  cin>> n >> k;
  int arrivals[n];
  for(int i=0; i<n; i++){
    cin>> arrivals[i];
  }
  sort(arrivals,arrivals+n);
  int L=0,R=1000000000, FINAL;

  while(L<=R){
    int number=1;
    int start=0;
    int M= L +(R-L)/2;

    for(int i=0; i<n; i++){
      if(arrivals[i]<=arrivals[start]+M){
        continue;
      }else{
        start=i;
        number++;
      }

    }

    if(number<=k){
      FINAL = M;
      R=M-1;
    }else{
      L=M+1;
    }

  }

  cout<< FINAL << '\n';
    return 0;
}
