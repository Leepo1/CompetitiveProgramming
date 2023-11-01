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
//ifstream cin("cari.txt");
//  ofstream cout("caro.txt");
  int c;
  cin>> c;
  while(c--){
    string s;
    cin>> s;
    if(s=="CAR"){
      cout<< "Arup" << '\n';
      continue;
    }else{
        if(s.find("CAR")!= string::npos){
          cout<< "Travis" <<'\n';
          continue;
        }else{
          cout<< "Unknown" << '\n';
        }
      }
    }



    return 0;
}
