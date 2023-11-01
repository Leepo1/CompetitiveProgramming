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
#include <unordered_map>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

map<int,int> m;
int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  cout.tie(0);
  //ifstream cin("naptimei.txt");
  //ofstream cout("naptimeo.txt");
  int t;
  cin>> t;
  while(t--){
    m.clear();

    int n;
    cin>> n;
    int start[n];

    for(int i=0; i<n; i++){
      int e;
      cin>> start[i] >> e;
      m[start[i]]= max(m[start[i]],e);
    }

    sort(start,start+n);
    int currstart = start[0];
    int currend = m[start[0]];

    vector<int> works;
    vector<int> gaps;

    for(int i=1; i<n; i++){
      if(start[i]<=currend){
        currend= max(currend,m[start[i]]);
        continue;
      }else{
        works.push_back(currend-currstart);
        currstart=start[i];
        gaps.push_back(currstart-currend);
        currend= m[start[i]];
        continue;
      }
    }
    works.push_back(currend-currstart);

    cout<< gaps.size() << " ";
    for(int i=0; i<gaps.size(); i++){
      cout<< gaps[i] << " ";
    }
    cout<< '\n';
    for(int i=0; i<works.size(); i++){
      cout<< works[i] << " ";
    }
    cout<< '\n';
  }
    return 0;
}
