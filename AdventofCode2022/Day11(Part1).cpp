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
typedef pair<long long,long long> ii;
typedef long long ll;


long long op(long long t , long long n){
  if(n==0) return t*=11;
  if(n==1) return t+=1;
  if (n==2) return t+=6;
  if (n==3) return t*=t;
  if(n==4) return t*=7;
  if(n==5) return t+=8;
  if(n==6) return t+=5;
  if(n==7) return t+=7;
}
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("Day11i.txt");
  ofstream cout("Day11o.txt");
  queue<long long> arr[8];
  long long d[8];
  long long tmonkey[8];
  long long fmonkey[8];
  long long pc[8];
  for(long long i=0; i<8; i++) pc[i]=0;

  vector<long long> zero = {89,95,92,64,87,68};

  for(auto u : zero){
    arr[0].push(u);
  }
  d[0]=2;
  tmonkey[0]=7;
  fmonkey[0]=4;


  vector<long long> one = {87,67};
  for(auto u : one){
    arr[1].push(u);
  }
  d[1]=13;
  tmonkey[1]=3;
  fmonkey[1]=6;


  vector<long long> two = {95,79,92,82,60};
  for(auto u : two){
    arr[2].push(u);
  }

  d[2]=3;
  tmonkey[2]=1;
  fmonkey[2]=6;

  vector<long long> three = {67,97,56};
  for(auto u : three){
    arr[3].push(u);
  }

  d[3]=17;
  tmonkey[3]=7;
  fmonkey[3]=0;

  vector<long long> four = {80,68,87,94,61,59,50,68};
  for(auto u : four){
    arr[4].push(u);
  }

  d[4]=19;
  tmonkey[4]=5;
  fmonkey[4]=2;

  vector<long long> five = {73,51,76,59};
  for(auto u : five){
    arr[5].push(u);
  }
  d[5]=7;
  tmonkey[5]=2;
  fmonkey[5]=1;

  vector<long long> six = {92};
  for(auto u : six){
    arr[6].push(u);
  }

  d[6]=11;
  tmonkey[6]=3;
  fmonkey[6]=0;

  vector<long long> seven = {99,76,78,76,79,90,89};
  for(auto u : seven){
    arr[7].push(u);
  }
  d[7]=5;
  tmonkey[7]=4;
  fmonkey[7]=5;

  for(long long r=0; r<10000; r++){
    for(long long i=0; i<8; i++){
      while(!arr[i].empty()){
        long long temp = arr[i].front();
        arr[i].pop();
        temp%=(2*13*3*17*19*7*11*5);
        temp = op(temp,i);

        pc[i]++;
        if(temp%(d[i])==0){
          arr[tmonkey[i]].push(temp);
        }else{
          arr[fmonkey[i]].push(temp);
        }
      }
    }
  }
  sort(pc,pc+8);
  cout<< pc[7]*pc[6] << '\n';

    return 0;
}
