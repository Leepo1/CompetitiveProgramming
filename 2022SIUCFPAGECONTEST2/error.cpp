#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <set>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;


set<string> ids;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ifstream cin("errori.txt");
  ofstream cout("erroro.txt");
  int c;
  cin>> c;
  while(c--){
    ids.clear();
    int n;
    cin>> n;
    string id;
    int time;
    int lower;
    int higher;
    bool check=true;

    for(int i=0; i<n; i++){
      cin>> id >> time >> lower >> higher;
      if(ids.find(id)!=ids.end()){
        check=false;
      }
      ids.insert(id);
      if(time<=0 || time>30){
          check=false;
      }
      if((lower%10)!=0 || (higher%10)!=0 || (lower+higher)!=100 || lower<=0 || higher<=0){
          check=false;
      }
    }

    if(check){
      cout<< "Correct! " << '\n';
    }else{
      cout<< "Internal Error (response 0) " << '\n';
    }

  }

    return 0;
}
