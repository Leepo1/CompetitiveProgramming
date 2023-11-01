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

map<char,int> f;
map<char,int> s;
int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  cout.tie(0);
  //ifstream cin("tilesi.txt");
  //ofstream cout("tileso.txt");
  int c;
  cin>> c;
  while(c--){
    f.clear();
    s.clear();
    string o,n;
    cin >> o >> n;
    int l= o.size();
    for(int i=0; i<l; i++){
      f[o[i]]=i;
      s[n[i]]=i;
    }

    int moves=0;

    for(int i=l-1; i>=0; i--){
      for(int j=s[o[i]]+1; j<=i; j++){
        s[n[j]]--;
        s[o[i]]++;
        moves++;
      }

    }

    cout<< moves << '\n';
  }
    return 0;
}
