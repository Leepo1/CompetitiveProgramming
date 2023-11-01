#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <iomanip>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
struct fruit{
  int x,y;

};

int distance(int x , int y , int x1 ,int y1){
  return abs(x1-x) + abs(y1-y);
}
int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  cout.tie(0);
  //ifstream cin("fruiti.txt");
  //ofstream cout("fruito.txt");
  int c;
  cin>> c;

  while(c--){
    int w,h;
    cin>> w >> h;
    vector<fruit> v;
    for(int i=0; i<w; i++){
      string s;
      cin>> s;
      for(int j=0; j<h; j++){
        if(s[j]!='.'){
          fruit a;
          a.x =i;
          a.y=j;
          v.push_back(a);
        }
      }
    }

    int l=v.size();
    fruit arr[l];
    int per[l];
    for(int i=0; i<l; i++){
      arr[i]=v[i];
      per[i]=i;
    }


    int answer=2400;

    do{
      int currx=0;
      int curry=0;


      int d=0;
      for(int i=0; i<l; i++){
        d+=distance(currx, curry, arr[per[i]].x , arr[per[i]].y);
        currx=arr[per[i]].x;
        curry=arr[per[i]].y;
      }
      d+= distance(currx, curry, w-1, h-1);
      answer=min(answer,d);
    }while(next_permutation(per,per+l));
    cout<< answer << '\n';

  }


    return 0;
}
