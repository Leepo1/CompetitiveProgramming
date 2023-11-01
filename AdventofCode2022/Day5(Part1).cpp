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
  ifstream cin("Day5(Part1)i.txt");
  ofstream cout("Day5(Part1)o.txt");
  vector<char> arr[9];
  arr[0]={'J','F','C','N','D','B','W'};
  arr[1]={'T','S','L','Q','V','Z','P'};
  arr[2]={'T','J','G','B','Z','P'};
  arr[3]={'C','H','B','Z','J','L','T','D'};
  arr[4]={'S','J','B','V','G'};
  arr[5]={'Q','S','P'};
  arr[6]={'N','P','M','L','F','D','V','B'};
  arr[7]={'R','L','D','B','F','M','S','P'};
  arr[8]={'R','T','D','V'};
  deque<char> d[9];
  for(int i=0; i<9; i++){
    for(int j=0; j<arr[i].size(); j++){
      d[i].push_back(arr[i][j]);
    }
  }
  string s;
  while(getline(cin,s)){
    stringstream ss(s);
    int number, from, to;
    string waste;
    ss>> waste >> number >> waste >> from >> waste >> to;
    vector<char> order;
    for(int i=0; i<number; i++){
      order.push_back(d[from-1].front());
      d[from-1].pop_front();
    }
    reverse(order.begin(),order.end());
    for(int i=0; i<order.size(); i++){
      d[to-1].push_front(order[i]);
    }
  }
  for(int i=0; i<9; i++){
    cout<< d[i].front();
  }

    return 0;
}
