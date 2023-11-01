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

string names[8] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};



map<string, int> m;

int main(){
  //ifstream cin("lineup.in");
  //ofstream cout("lineup.out");
  int n;
  cin>> n;
  string arr[n][2];
  for(int i=0; i<n; i++){
    string s;
    string t;
    string e;
    cin>> s;
    cin>> e;
    cin>> e;
    cin>> e;
    cin>> e;
    cin>> t;
    arr[i][0]=s;
    arr[i][1]=t;

  }
  sort(names,names+8);

    do{
      for(int i=0; i<8; i++){
        m[names[i]]=i;
      }
      bool flag=true;
      for(auto x : arr){
        if(abs(m[x[0]]-m[x[1]])!=1){
          flag=false;
          break;
        }
      }

      if(flag){
        for(int i=0; i<8; i++){
          cout<< names[i] << '\n';
        }
        return 0;
      }
    }while(next_permutation(names,names+8));





    return 0;
}
