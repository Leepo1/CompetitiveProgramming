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
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;


int main(){

  //ifstream cin("PeacockPartyi.txt");
  //ofstream cout("PeacockPartyo.txt");
  int n;
  cin>> n;

  queue<string> feathers;
  for(int i=0; i<n; i++){
    int par;
    cin>> par;
    if(par==1){
      string b;
      cin>> b;
      feathers.push(b);
    }else{
      cout<< feathers.front() << '\n';
      string temp=feathers.front();
      feathers.pop();
      feathers.push(temp);
    }
  }


    return 0;
}
