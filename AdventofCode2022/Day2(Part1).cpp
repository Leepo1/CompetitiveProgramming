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
#include <sstream>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("Day2(Part1)i.txt");
  ofstream cout("Day2(Part1)o.txt");
  char opp;
  int score=0;
  while(cin>> opp){
    char your; cin>> your;
    if(your=='X'){
      if(opp=='A'){
        score+=3;
      }
      if(opp=='B'){
        score+=1;
      }
      if(opp=='C'){
        score+=2;
      }
    }
    if(your=='Z'){
      if(opp=='A'){
        score+=2;
        score+=6;
        continue;
      }
      if(opp=='B'){
        score+=6;
        score+=3;
        continue;
      }
      if(opp=='C'){
        score+=6;
        score+=1;
        continue;
      }
    }
    if(your=='Y'){
      score+=3;
      if(opp=='A'){
        score+=1;
      }else if(opp=='B'){
        score+=2;
      }else{
        score+=3;
      }
    }
  }
  cout<< score << '\n';

    return 0;
}
