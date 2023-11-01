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
  ifstream cin("1744C(1200)-TrafficLighti.txt");
  ofstream cout("1744C(1200)-TrafficLighto.txt");
  int t; cin>> t;
  while(t--){
    int n; cin>> n;
    char c; cin>> c;
    string s; cin>> s;
    vector<int> greenspots;
    for(int i=0; i<n; i++){
        if(s[i]=='g') greenspots.push_back(i);
    }
    greenspots.push_back((greenspots[0]+n));

    int answer=0;
    for(int i=0; i<n; i++){
        if(s[i]==c){
          int temp = abs((lower_bound(greenspots.begin(),greenspots.end(),i)-greenspots.begin())-i);
          answer = max(answer,temp);
        }
    }
    cout<< answer << '\n';
  }

    return 0;
}
