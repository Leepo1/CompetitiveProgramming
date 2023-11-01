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
  ifstream cin("Day1(Part1)i.txt");
  ofstream cout("Day1(Part1)o.txt");
  string s;
  int curr=0;
  vector<long long> v;
  while(getline(cin,s)){
    if(s==""){
      v.push_back(curr);
      curr=0;
    }else{
      curr+= stoi(s);
    }
  }
  sort(v.begin(),v.end());
  int l = v.size();
  long long answer =v[l-1]+v[l-2]+v[l-3];
  cout<< answer << '\n';
    return 0;
}
