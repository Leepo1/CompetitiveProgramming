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

map<string,vector<pair<int,string>>> adj;

vector<string> names;
map<string,bool> con;
set<string> check;

/*
bool recurse(string s){
  if(s=="shiny gold"){
    return true;
  }
  for(int i=0; i<adj[s].size(); i++){
    if(adj[s][i]=="shiny gold"){
      return true;
    }else{
      if(recurse(adj[s][i])){
        return true;
      }
    }
  }
}
*/
int count(string s){
  int answer=1;
  for(int i=0; i<adj[s].size(); i++){
    answer+= adj[s][i].first*count(adj[s][i].second);
  }
  return answer;
}

int main(){

  ifstream cin("Day7-HandyHaversacksi.txt");
  ofstream cout("Day7-HandyHaversackso.txt");

  string s;
  while(getline(cin,s)){
    vector<string> curr;

    stringstream temp(s);

    string word;
    while(temp >> word){
      curr.push_back(word);
    }
    string first, second;
    first=curr[0];
    second=curr[1];
    string name = first + " " + second;
    if(check.find(name)==check.end()){
      names.push_back(name);
      check.insert(name);
    }
    if(curr[4]=="no"){
      continue;
    }

    for(int i=4; i<curr.size(); i++){
      if(curr[i].substr(0,3)=="bag"){
        int amount= stoi(curr[i-3]);
        string f=curr[i-2],s=curr[i-1];
        string a= f + " " + s;

        if(check.find(a)==check.end()){
          names.push_back(a);
          check.insert(a);
        }

        adj[name].push_back({amount,a});
      }
    }
  }

  cout<< count("shiny gold");
    return 0;
}
