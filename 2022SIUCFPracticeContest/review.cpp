#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

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

struct p{
  int j1;
  int j2;
};

int problems, judges;
vector<p> set1;
vector<p> set2;
vector<int> judge1;
vector<int> judge2;
bool w;

// This is a function that checks if works
bool works(){
  for(int i=0; i<set1.size(); i++){
    if(count(judge1.begin(),judge1.end(),set1[i].j1) || count(judge1.begin(),judge1.end(),set1[i].j2)){
      continue;
    }else{
      return false;
    }
  }
  for(int i=0; i<set2.size(); i++){
    if(count(judge2.begin(),judge2.end(),set2[i].j1) || count(judge2.begin(),judge2.end(),set2[i].j2)){
      continue;
    }else{
      return false;
    }
  }
  return true;
}

int main(){
  //ifstream cin("reviewi.txt");
  //ofstream cout("reviewo.txt");
  int t;
  cin>> t;
  while(t--){
    cin>> problems >> judges;
    p arr[problems];
    int a;

    for(int i=0; i<problems; i++){
      cin>> arr[i].j1 >> arr[i].j2;
      cin>> a;
      if(a==1){
        set1.push_back(arr[i]);
      }else if(a==2){
        set2.push_back(arr[i]);
      }else{
        set1.push_back(arr[i]);
        set2.push_back(arr[i]);
      }
    }

    int number=0;

    for(int i=0; i<(1<<judges); i++){
      string something= tobin(number);
      int zeros= judges- something.size();

      for(int j=0; j<zeros; j++){
        something= "0"+something;
      }

      for(int j=0; j<something.size(); j++){
        if(something[j]=='0'){
          judge1.push_back(j+1);
        }else{
          judge2.push_back(j+1);
        }

      }

      w=false;

      if(works()){
        w=true;
        cout<< "We can do it!" << endl;
        break;
      }

      number++;
      judge1.clear();
      judge2.clear();
    }
    if(!w){
      cout<< "Better luck next time." << endl;
    }
    judge1.clear();
    judge2.clear();
    set1.clear();
    set2.clear();
  }

  return 0;
}
