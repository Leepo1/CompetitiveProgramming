#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
using namespace std;
typedef pair<long long,long long> pii;
typedef long long ll;


long long works(long long arr[],long long size, long long value){
  long long bags=0;
  long long temp[size];
  for(long long i=0; i<size; i++){
    temp[i]=arr[i];
  }
  for(long long i=0; i<size-1; i++){
    if(temp[i]==value){
      continue;
    }else {
      if(temp[i]<value){
        break;
      }
      bags=bags+ (temp[i]-value);
      temp[i+1]= temp[i+1]-(temp[i]-value);
      temp[i]= value;
    }
  }
  long long count=0;
  for(long long i=0; i<size; i++){
    if(temp[i]!=value){
      return -1;
  }
}
return 2*bags;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
  long long t;
  cin>> t;


  while(t--){
    long long size;
    cin>> size;
    long long arr[size];
    long long m=1000000000;
    for(long long i=0; i<size; i++){
      cin>> arr[i];
      m=min(m,arr[i]);
    }
    bool thumb=false;
    long long possible;
    if(size%2==1){
    for(long long i=m; i>=0; i--){
       if(works(arr,size,i)!=-1){
         thumb=true;


         possible=works(arr,size,i);
         break;
      }
    }
    if(thumb==true){
      cout<< possible << endl;
      continue;
    }
    cout<< -1 << endl;
  }else {
    long long L=0;
    long long R=m;
    while(L<=R){
      long long MID=L+(R-L)/2;
      if(works(arr,size,MID)!=-1){
        thumb=true;
        possible=works(arr,size,MID);
        L=MID+1;
      }else {
        R=MID-1;
      }
    }
    if(thumb==true){
      cout<< possible << endl;
      continue;
    }
    cout<< -1 << endl;
  }
  }

    return 0;
}
