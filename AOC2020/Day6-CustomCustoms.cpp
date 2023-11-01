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
#include <sstream>
#include <stack>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;


int main(){
  ifstream cin("Day6-CustomCustomsi.txt");
  ofstream cout("Day6-CustomCustomso.txt");

  map<char,int> check;
  for(char i='a'; i<='z'; i++){
    check[i]=0;
  }

  int pc=0;
  string s;
  int sum=0;
  while(getline(cin,s)){
    if(s.size()==0){
      for(char i= 'a' ; i<='z'; i++){
        if(check[i]==pc){
          sum++;
        }
      }
      for(char i='a'; i<='z'; i++){
        check[i]=0;
      }
      pc=0;
    }

    stringstream temp(s);

    string word;

    while(temp >> word){
      pc++;
      for(int i=0; i<word.size(); i++){
        check[word[i]]++;
      }
    }

  }

  for(char i= 'a' ; i<='z'; i++){
    if(check[i]==pc){
      sum++;
    }
  }
  for(char i='a'; i<='z'; i++){
    check[i]=0;
  }
  pc=0;

  cout<< sum << '\n';
    return 0;
}
