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
int total=0;
int acc=0;
vector<string> command;
vector<int> amount;
bool visited[1000];

bool simulate(){
  int curr=0;
  while(true){
    if(visited[curr]) return false;
    visited[curr]=true;
    if(command[curr]=="jmp"){
      curr+=amount[curr];
    } else if(command[curr]=="acc"){
      acc+=amount[curr];
      curr+=1;
    }else if(command[curr]=="nop"){
      curr+=1;
    }
    if(curr==total) return true;

  }

}

int main(){

  ifstream cin("Day8-HandheldHaltingi.txt");
  ofstream cout("Day8-HandheldHaltingo.txt");

  string s;

  while(getline(cin,s)){
    total++;
    stringstream temp(s);
    string c, n;
    temp >> c >> n;

    int number= stoi(n.substr(1,n.size()-1));

    if(n[0]=='-'){
      number*=-1;
    }

    command.push_back(c);
    amount.push_back(number);
  }


  for(int i=0; i<command.size(); i++){

    if(command[i]=="jmp"){

      command[i]="nop";
      if(simulate()){
        cout<< acc << '\n';
        break;
      }
      for(int i=0; i<1000; i++){
        visited[i]=false;
      }
      command[i]="jmp";
      acc=0;

    }else if(command[i]=="nop"){

      command[i]="jmp";
      if(simulate()){
        cout<< acc << '\n';
        break;
      }
      for(int i=0; i<1000; i++){
        visited[i]=false;
      }
      acc=0;
      command[i]="nop";
    }

  }




    return 0;
}
