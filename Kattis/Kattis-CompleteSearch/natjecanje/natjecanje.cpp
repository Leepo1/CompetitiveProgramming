#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <set>
#include <map>
#include <vector>

using namespace std;
map<int,int> reserved;
map<int, vector<int> > arr;
int main(){


  //ifstream cin("natjecanjei.txt");
  //ofstream cout("natjecanjeo.txt");
  int n,d,r;
  int badcount=0;

  cin>> n >> d >> r;
  int a;
  int damaged[d];
  for(int i=0; i<d; i++){
    cin>> damaged[i];
  }
  for(int i=0; i<r; i++){
    cin>> a;
    reserved[a]=true;
  }
  for(int i=0; i<d; i++){
    if(reserved[damaged[i]-1]==true){
      arr[damaged[i]].push_back(damaged[i]-1);
    }else if(reserved[damaged[i]+1]==true){
      arr[damaged[i]].push_back(damaged[i]+1);
    }
  }
  for(int i=0; i<d; i++){
    if(arr[damaged[i]].size()==0){
      badcount++;
    }else if(arr[damaged[i]].size()==1){
      if(arr[damaged[i]][0]>damaged[i]){
        if(damaged[i]+2<n){
          if(i!=d-1){
          if(damaged[i+1]==damaged[i]+2){
        arr[damaged[i]+2].erase(arr[damaged[i]+2].begin()+0);
          }
        }
      }
      }
    }
  }
  cout<< badcount;
  return 0;
}
