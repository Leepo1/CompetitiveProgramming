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
  //ifstream cin("nightnestingi.txt");
  //ofstream cout("nightnestingo.txt");
  long long n,m;
  cin>> n >> m;
  long long answer= n/m;
  if(n%m!=0){
    answer+=1;
  }
  cout<< answer;
    return 0;
}
