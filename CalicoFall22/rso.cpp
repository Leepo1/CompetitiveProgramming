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


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  //ifstream cin("rsoi.txt");
  //ofstream cout("rsoo.txt");
  int t; cin>> t;
  while(t--){
    int year; cin>> year;
    string waste;
    getline(cin,waste);
    string n;
    getline(cin,n);
    if(n.size()>50){
      cout << "INVALID" << '\n';
      continue;
    }
    int index;
    for(int i=0; i<n.size(); i++){
      if(n[i]==' '){
        index=i;
        break;
      }
    }
    string f = n.substr(0,index);
    string actual="";
    for(int i=0; i<f.size(); i++){
      actual+= tolower(f[i]);
    }

    if(actual=="cal" || actual=="berkeley" || actual=="california"){
      if(year<2010){
        cout<< "VALID" << '\n';
        continue;
      }
      cout<< "INVALID" << '\n';
      continue;
    }
    cout<< "VALID" << '\n';
  }

    return 0;
}
