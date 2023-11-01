#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
map<string,int> m;
int main(){
  //ifstream cin("editori.txt");
  //ofstream cout("editoro.txt");
  int c;
  cin>> c;
  while(c--){
  m.clear();
  vector<string> v;
  int n;
  cin>> n;
  string ans="";
  double currmax=0;

  for(int i=0; i<n; i++){
    string s;
    string ne="";
    cin>> s;
    for(char c : s){
      c= tolower(c);
      ne+=c;
    }
    if(ne[ne.size()-1]=='.' || ne[ne.size()-1]==','){
      ne=ne.substr(0,ne.size()-1);
    }
    m[ne]++;
    double p = (double)m[ne]/n;

    if(p>=.1){
      if(p>currmax){
        currmax=p;
        ans=ne;
      }else if(p==currmax){
        v.push_back(ans);
        v.push_back(ne);
        sort(v.begin(),v.end());
        ans= v[0];
      }

    }

  }
  if(ans==""){
  cout<< "Looks good!" << '\n';
  }else{
    cout<< ans << '\n';
  }


}


  return 0;
}
