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
typedef pair<long long, long long> ll;
long long sx,sy,bx,by;
vector<long long> md;
vector<ll> sensors;
long long d(ll sensor, ll beacon){
  return abs(beacon.first-sensor.first) + abs(beacon.second-sensor.second);
}
set<ll> used;
bool checkifnotinsensors(ll point){
  for(int i=0; i<sensors.size(); i++){
    if(d(point,sensors[i])<=md[i] && used.find(point)==used.end()) return false;
  }
  return true;
}
bool pointinbound(ll point){
  if(point.first<0 || point.first>4000000) return false;
  if(point.second<0 || point.second>4000000) return false;
  return true;
}
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("Day15i.txt");
  ofstream cout("Day15o.txt");
//6804272292212

  while(cin>> sx >> sy >> bx >> by){
    long long manhat = abs(bx-sx) + abs(by-sy);
    ll temp; temp.first=bx; temp.second=by;
    used.insert(temp);
    temp.first=sx; temp.second=sy;
    sensors.push_back(temp);
    md.push_back(manhat);
  }
  int d=1;
  while(true){
    for(int i=0; i<sensors.size(); i++){
      long long total = md[i]+d;
      for(int j=-total; j<=total; j++){
        ll temp; temp.first=sensors[i].first+j; temp.second=sensors[i].second+ total-abs(j);
        if(checkifnotinsensors(temp)){
          if(!pointinbound(temp)) continue;
          long long answer=temp.first*4000000+temp.second;
          cout<< answer << '\n';
          cout<< d;
          return 0;
        }
        temp.second = sensors[i].second + -1*(total-abs(j));
        if(checkifnotinsensors(temp)){
          if(!pointinbound(temp)) continue;
          long long answer=temp.first*4000000+temp.second;
          cout<< answer << '\n';
          cout<< d;
          return 0;
        }
      }
    }
    d++;
  }
    return 0;
}
