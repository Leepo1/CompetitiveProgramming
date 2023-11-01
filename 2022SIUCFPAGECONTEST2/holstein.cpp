#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  //ifstream cin("holsteini.txt");
  //ofstream cout("holsteino.txt");
  int c;
  cin>> c;
  while(c--){
    int n,x;
    cin>> n >> x;
    int value[n];
    int weight[n];
    for(int i=0; i<n; i++){
      cin>> value[i];
    }
    for(int i=0; i<n; i++){
      cin>> weight[i];
    }
    int answer=0;

    for(int i=0; i<n; i++){
      int wcurr=weight[i];
      if(wcurr>x){
        continue;
      }
      int curr=value[i];
      answer=max(answer,curr);
      for(int j=i+1; j<n; j++){
        wcurr+=weight[j];
        if(wcurr>x){
          break;
        }
        curr+=value[j];
        answer=max(answer, curr);
      }
    }
    cout<< answer << '\n';
  }

    return 0;
}
