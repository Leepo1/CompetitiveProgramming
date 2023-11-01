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
  //ifstream cin("dropi.txt");
  //ofstream cout("dropo.txt");
  int c;
  cin>> c;
  while(c--){
    long long n;
    cin>> n;
    long long answer= n*n;
    cout<< answer << '\n';
  }

    return 0;
}
