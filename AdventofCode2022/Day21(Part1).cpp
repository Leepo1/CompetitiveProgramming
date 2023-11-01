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


bool isnumber(string example){
  for(long long i=0; i<example.size(); i++){
    if(!isdigit(example[i])) return false;
  }
  return true;
}

map<string,long long> values;
map<string,string> f;
map<string,char> operation;
map<string,string> si;
map<string,bool> hasvalue;
long long starting = 72950437237500;

long long monkey(string n){
  if(hasvalue[n]) return values[n];
  if(operation[n]=='+'){
    return monkey(f[n])+monkey(si[n]);
  }
  if(operation[n]=='-'){
    return monkey(f[n])-monkey(si[n]);
  }
  if(operation[n]=='/'){
    return monkey(f[n])/monkey(si[n]);
  }
  if(operation[n]=='*'){
    return monkey(f[n])*monkey(si[n]);
  }
  return -1;
}

bool hashuman(string name){
  if(name=="humn") return true;
  if(hasvalue[name]) return false;
  if(hashuman(f[name]) || hashuman(si[name])) return true;
  return false;
}

long long determinehumn(string name){
  cout<< name << '\n';
  if(hashuman(f[name])){
    if(operation[name]=='+'){
      starting-=monkey(si[name]);
    }else if(operation[name]=='-'){
      starting+=monkey(si[name]);
    }else if(operation[name]=='*'){
      starting/=monkey(si[name]);
    }else if(operation[name]=='/'){
      starting*=monkey(si[name]);
    }
    cout<< starting<< '\n';
    if(f[name]=="humn") return starting;
    return determinehumn(f[name]);
  }else if(hashuman(si[name])) {
    if(operation[name]=='+'){
      starting-=monkey(f[name]);
    }else if(operation[name]=='-'){
      starting-=monkey(f[name]);
      starting*=-1;
    }else if(operation[name]=='*'){
      starting/=monkey(f[name]);
    }else if(operation[name]=='/'){
      starting= monkey(f[name])/starting;
    }
    cout<< starting << '\n';
    if(si[name]=="humn") return starting;
    return determinehumn(si[name]);
  }
}

int main(){

  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("Day21i.txt");
  //ofstream cout("Day21o.txt");
  string s;
  while(getline(cin,s)){
    stringstream ss(s);
    string name,nex;
    ss>> name >> nex;
    if(isnumber(nex)){
      hasvalue[name]=true;
      values[name]= stoi(nex);
      continue;
    }
    char op; ss >> op;
    string las; ss >> las;
    f[name]=nex;
    operation[name]=op;
    si[name]=las;
  }

  values["humn"]= determinehumn(f["root"]);
  cout<< monkey(f["root"]) << '\n';
  cout<< monkey(si["root"]) <<'\n';



    return 0;
}
