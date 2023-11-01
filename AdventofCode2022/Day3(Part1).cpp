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

map<char,int> m;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("Day3(Part1)i.txt");
  ofstream cout("Day3(Part1)o.txt");
  string s;
  int answer=0;
  while(cin>> s){
    m.clear();
    string a,b;
    cin>> a >> b;
    set<char> used;
    for(int i=0; i<s.size(); i++){
      if(used.find(s[i])==used.end()){
        m[s[i]]++;
        used.insert(s[i]);
      }
    }
    used.clear();
    for(int i=0; i<a.size(); i++){
      if(used.find(a[i])==used.end()){
        m[a[i]]++;
        used.insert(a[i]);
      }
    }
    used.clear();
    for(int i=0; i<b.size(); i++){
      if(used.find(b[i])==used.end()){
        m[b[i]]++;
        used.insert(b[i]);
      }
    }
    bool found=false;
    for(char a = 'a'; a<='z'; a++){
      if(m[a]==3){
        int num;
        num = a-'a'+1;
        answer+=num;
        found=true;
        break;
      }
    }
    if(found) continue;
    for(char a='A'; a<='Z'; a++){
      if(m[a]==3){
        int num;
        if(m[a]==3){
          num = a-'A'+27;
          answer+=num;
          found=true;
          break;
        }
      }
    }
  }

  cout<< answer << '\n';
    return 0;
}
