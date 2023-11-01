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


int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  cout.tie(0);
  //ifstream cin("givingi.txt");
  //ofstream cout("givingo.txt");
  int c;
  cin>> c;
  while(c--){
    int total, blaze, n;
    cin >> total >> blaze >> n;
    int cookies[n];
    for(int i=0; i<n; i++){
      cin>> cookies[i];
    }
    sort(cookies,cookies+n);
    int number=0;
    int currsum=0;
    for(int i=0; i<n; i++){
      currsum+=cookies[i];
      if(currsum<=(total-blaze)){
        number++;
      }else{
        break;
      }
    }
    cout<< (n-number)<< '\n';
  }

    return 0;
}
