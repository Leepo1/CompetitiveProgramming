#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <iomanip>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int,int> pi;
typedef long long ll;
typedef pair<int,pair<int,int>> pii;


int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  cout.tie(0);
  //ifstream cin("templei.txt");
  //ofstream cout("templeo.txt");
  int c;
  cin>> c;
  while(c--){
    long long cost, points, req;
    cin>> cost >> points >>req;
    long long games=0;
    if(req%points!=0){
      games = req/points +1;
    }else{
      games = req/points;
    }
    cout<< cost*games << '\n';
  }
    return 0;
}
