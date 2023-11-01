#include <iostream>
#include <queue>
#include <algorithm>
#include <fstream>

using namespace std;
struct knight{
  int start;
  int end;
  int qual;
  int will;
};

priority_queue<knight, vector<knight>, less<knight>) candidates;
int main(){
  ifstream cin("knighti.txt");
  ofstream cout("knighto.txt");
  // Add c
  int n;
  cin>> n;
  knight group[n];
  int begin=5000;
  for(int i=0; i<n; i++){
    cin>> group[i].start >> group[i].end >> group[i].qual >> group[i].will;
    candidates.push(group[i]);
    begin=min(begin, group[i].start);
  }





  return 0;
}
