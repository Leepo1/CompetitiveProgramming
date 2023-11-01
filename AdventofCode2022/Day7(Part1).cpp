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
#include <stack>
#include <sstream>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;

map<string, long long> sz;
map<string,vector<string>> directories;
set<string> used;
vector<long long> v;
long long answer=70000000;
long long dels;
bool t=false;
long long rs(string a){
  for(auto u : directories[a]){
    sz[a]+=rs(u);
  }
  v.push_back(sz[a]);
  return sz[a];
}
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("Day7(Part1)i.txt");
  ofstream cout("Day7(Part1)o.txt");

  string s;
  string curr;
  stack<long long> where;

  while(getline(cin,s)){
    stringstream ss(s);
    string word; ss>> word;
    if(word=="$"){
      string command; ss >> command;
      if(command=="cd"){
        string dir; ss >> dir;
        if(dir==".."){
         curr= curr.substr(0,curr.size()-where.top());
         where.pop();
         continue;
       }else{
         curr+=dir;
         where.push(dir.size());
         continue;
       }
     }
  }else{
    string f;
    ss >> f;
    if(word=="dir"){
      string temp=curr+f;
      directories[curr].push_back(temp);
    }else{
      sz[curr]+= stoi(word);
    }
  }
}

rs("/");
long long unused = 70000000-sz["/"];
long long dels= 30000000-unused;
for(auto u : v){
  if(u>=dels){
    answer=min(answer,u);
  }
}

cout<< answer << '\n';

    return 0;
}
