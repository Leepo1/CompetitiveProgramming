#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>

using namespace std;
vector<int> pyramid;
bool w;

string tobin(int n){
  string str="";
  while(n>0){
    if(n%2==1){
      str="1"+str;
    }else{
      str="0"+str;
    }
    n/=2;
  }
  return str;
}

bool works(){
  int l= pyramid.size();
  if(pyramid.size()%2==0){
    return false;
  }
  vector<int> pp;
  for(int x: pyramid){
    pp.push_back(x);
  }
  reverse(pp.begin(),pp.end());
  for(int i=0;i<pp.size();i++){
    if(pp[i]!=pyramid[i]){
      return false;
    }
  }


  for(int i=0; i<l/2; i++){
    if(pyramid[i+1]<=pyramid[i]){
      return false;
    }
  }
  for(int i=l/2; i<l-1; i++){
    if(pyramid[i]<=pyramid[i+1]){
      return false;
    }
  }
  return true;
}

int main(){
  //ifstream cin("pyramidsi.txt");
  //ofstream cout("pyramidso.txt");













































  int t;
  cin>> t;

  while(t--){
    int maximum=0;
    int n;
    cin>> n;
    int arr[n];
    for(int i=0; i<n; i++){
      cin>> arr[i];
    }
    int number=0;
    for(int i=0; i<=(1<<n); i++){
      string something= tobin(number);
      int zeros= n- something.size();

      for(int j=0; j<zeros; j++){
        something= "0"+something;
      }

      for(int j=0; j<something.size(); j++){
        if(something[j]=='1'){
          pyramid.push_back(arr[j]);
        }
      }
      // for(int x: pyramid){
      //   cout<<x<<" ";
      // }
      // cout<<"#####"<<endl;

      if(works()){
      //  cout<<" MOOOOOO "<<endl;
        int temp= pyramid.size();
        maximum= max(maximum,temp);
      }
      number++;
      pyramid.clear();
    }
    if(maximum==1){
      cout<< 0 << endl;
    }else{
      cout<< maximum << endl;
    }

  }


  return 0;
}
