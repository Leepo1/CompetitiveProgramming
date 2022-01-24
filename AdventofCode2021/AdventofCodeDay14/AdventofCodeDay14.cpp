#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <stdlib.h>
#include <utility>
#include <stack>
using namespace std;
map<string,char> change;
map<string,int> values;
map<char,long long> answers;
int main(){
  long long maximum=1;
  long long minimum=1;
  ifstream cin("AdventofCodeDay14.in");
  ofstream cout("AdventofCodeDay14.out");
  string s;
  cin>> s;
  for(int i=3; i<=102;  i++){
    string a,b,c;
    cin>> a >>b >>c;
    change[a]=c;
  }
  for(int i=0; i<s.size()-1; i++){
    values[s.subtr(i,2)]+=1;
  }


for(int q=0; q<10; q++){
  map<string,int> copy(values);
  for(string i : values){
    for(string j : changes){
      if (i==j){
        int times= values[i];
        copy[i]=0;
        copy[i[0]+change[i]] +=times;
        copy[change[i]+i[1]]+=times;
        break;
      }
    }
  }
}
for(string i :values){
  answers[i[0]]+=1;
  answers[i[1]]+=1;
}
for(char d ='A'; d<='Z'; d++){
  if(answers[d]!=0){
    maximum= max(maximum,answers[d]);
    minimum= min(minimum,answers[d]);
  }
}
cout<< maximum-minimum;
    return 0;
  }
