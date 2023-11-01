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
  ifstream cin("Day2-PasswordPhilosophyi.txt");
  ofstream cout("Day2-PasswordPhilosophyo.txt");
  int low;
  int high;
  char letter;
  string pass;
  int validcount=0;
  int lc=0;
  while(cin>> low){
    lc=0;
    cin>> high >> letter >> pass;
    if(pass[low-1]==letter){
      lc++;
    }
    if(pass[high-1]==letter){
      lc++;
    }
    if(lc==1){
      validcount++;
    }

  }
  cout<< validcount;

    return 0;
}
