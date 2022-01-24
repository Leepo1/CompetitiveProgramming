#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main(){
  ifstream cin("hangman.in");
  ofstream cout("hangman.out");
  int t;
  cin>> t;
  for(int q=0; q<t; q++){
    string category;
    cin>> category;
    int n,l;
    cin>> n;
    string arr[n];
    for(int i=0; i<n; i++){
      cin>> arr[i];
    }
    cin>> l;
    string brr[l];
    for(int i=0; i<l; i++){
      cin>> brr[i];
    }
    for(int i=0; i<l; i++){
      for(int j=0; j<n; j++){
        if(brr[i].size()==arr[j].size()){
          int count=0;
      map<char,bool> m;
          for(int g=0; g<arr[j].size(); g++){
            if((brr[i][g]=='_' && m[arr[j][g]]==false) || (brr[i][g]==arr[j][g])) {
              count=count+1;
            m[brr[i][g]]=true;
            }
          }
          if(count==arr[j].size()){
            cout<< "No cheaters here!";
            if(i!=l-1){
              cout<< endl;
            }
            break;
          }
        }

          if(j==n-1){
            cout<< "That's not a word for a(n) " << category << "!";
            if(i!=l-1){
              cout<< endl;
            }
          }
          }

        }
    }

    return 0;

}
