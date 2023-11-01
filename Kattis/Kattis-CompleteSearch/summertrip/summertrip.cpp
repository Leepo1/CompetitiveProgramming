#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <set>


using namespace std;

set<string> vacations;
set<char> used;
int main(){
  int count=0;

//  ifstream cin("summertripi.txt");
 //ofstream cout("summertripo.txt");
  string s;
  cin>> s;
  for(int i=0; i<s.size()-1; i++){
    used.clear();
    string curr="";
    curr+=s[i];
    for(int j=1; j<s.size()-i; j++){
      if(s[i+j]==s[i]){
        break;
      }else if(used.find(s[i+j])==used.end()){
        used.insert(s[i+j]);
        vacations.insert(curr);
        count++;
      }
      curr+=s[i+j];
  }
}
  cout<< count;


  return 0;
}
