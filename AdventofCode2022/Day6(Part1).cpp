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
  ifstream cin("Day6(Part1)i.txt");
  ofstream cout("Day6(Part1)o.txt");
  string s; cin>> s;
  for(int i=0; i<s.size()-4; i++){
    set<char> si;
    bool works=true;
    for(int j=0; j<14; j++){
      if(si.find(s[i+j])==si.end()){
        si.insert(s[i+j]);
        continue;
      }else{
        works=false;
        break;
      }
    }
    if(works) cout << i+14 << '\n';
  }


    return 0;
}
