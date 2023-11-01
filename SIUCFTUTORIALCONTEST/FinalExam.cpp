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
  //ifstream cin("i.txt");
  //ofstream cout("o.txt");
  int n;
  cin>> n;
  char answers[n];
  char prev;
  cin>> prev;
  char next;
  int score=0;
  for(int i=1; i<n; i++){
    cin>> next;
    if(next==prev){
      score++;
    }
    prev=next;
  }
  cout<< score << '\n';
    return 0;
}
