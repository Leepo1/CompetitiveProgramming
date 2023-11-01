#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int mfn(int a, int b){
  if(a>=0){
    return a%b;
  }else {
    while(a<0){
      a+=b;
    }
    return a;
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("FineasCypher.in");
  ofstream cout("FineasCypher.txt");

  int n;
  cin>> n;

  int poschange[n];
  int shiftchange[n];

  for(int i=0; i<n; i++){
  cin>> poschange[i] >> shiftchange[i];
  }

  string s;
  vector<string> words;

  while(cin >> s) {
    words.push_back(s);
  }
  int l=words.size();
  string rwords[l];
  for(int q=0; q<n; q++){
    if(q!=0){
      for(int j=0; j<l; j++){
        words[j]=rwords[j];
      }
    }
    for(int i=0; i<l; i++){
      string replace= "";
      if(poschange[q]==0){
      replace= replace + words[mfn((i-shiftchange[q]),(l))][0];
      replace= replace + words[i].substr(1,words[i].size()-1);
      }else {
      replace= replace + words[i].substr(0,poschange[q]);
      replace= replace+ words[mfn((i-shiftchange[q]),(l))][poschange[q]];
      if(poschange[q]!=words[i].size()-1){
      replace=replace + words[i].substr(poschange[q]+1,words[i].size()-poschange[q]-1);
    }
      }
      rwords[i]=replace;
    }
  }

  for(int i=0; i<words.size(); i++){
    cout<< rwords[i]<< " ";
  }




//OFFICIAL SOLUTION
/*
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
// New MOD function that works on negative numbers
int mfn(int a, int b){
  if(a>=0){
    return a%b;
  }else {
    while(a<0){
      a+=b;
    }
    return a;
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; // Number of changes
  cin>> n;

  int poschange[n]; // Contains ith position change
  int shiftchange[n]; // Contains ith shift change

  for(int i=0; i<n; i++){
      cin>> poschange[i] >> shiftchange[i];
  }

  string s;
  vector<string> words; // Contains words of string

  while(cin >> s) {
    words.push_back(s);
  }
  int l=words.size();

  string rwords[l];
  for(int q=0; q<n; q++){
    // Replaces old string with new string once all words have been changed
    if(q!=0){
      for(int j=0; j<l; j++){
        words[j]=rwords[j];
      }
    }

    for(int i=0; i<l; i++){
      string replace= "";
      if(poschange[q]==0){
          replace= replace + words[mfn((i-shiftchange[q]),(l))][0]; // Changes character at 0th position
          replace= replace + words[i].substr(1,words[i].size()-1); // Adds the rest of the word back
      }else {
          replace= replace + words[i].substr(0,poschange[q]); // Maintains the characters until the position change
          replace= replace+ words[mfn((i-shiftchange[q]),(l))][poschange[q]]; // Adds the changed position
          int h= words[i].size();
          if(poschange[q]!=h-1){
          replace=replace + words[i].substr(poschange[q]+1,words[i].size()-poschange[q]-1); // Adds the characters after the position change
          }
      }
      rwords[i]=replace;
    }
  }

  for(int i=0; i<l; i++){
    cout<< rwords[i]<< " ";
  }

 return 0;
}
*/
 return 0;
}
