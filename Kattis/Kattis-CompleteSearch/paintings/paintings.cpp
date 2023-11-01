#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <set>
#include <map>
#include <vector>

using namespace std;
map<string,vector<string> > badpairs;
vector<string> answer;
int main(){

  ifstream cin("paintingsi.txt");
  ofstream cout("paintingso.txt");
  int t;
  cin>> t;
  while(t--){
    badpairs.clear();
    answer.clear();
    int n;
    cin>> n;
    vector<string> order;
    int temp;
    for(int i=0; i<n; i++){
      cin>> temp;
      order.push_back(temp);
    }
    int p;
    cin>> p
    string a,b;
    for(int i=0; i<p; i++){
        cin>> a >> b;
        badpairs[a].push_back(b);
        badpairs[b].push_back(a);
      }
      for(int i=0; i<n; i++){
        if(i==0){
          answer.push_back(order[i]);
        }else {
          if(badpairs[order[i]].find(order[i-1])==badpairs[order[i]].end()){
            answer.push_back(order[i]);

          }else{

          }







        }

      }



  }

  return 0;
}
