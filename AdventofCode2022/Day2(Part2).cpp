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
  ifstream cin("Day2(Part2)i.txt");
  ofstream cout("Day2(Part2)o.txt");

  if(opp=='A'){
    if(your=='X'){
      score+=3;
    }
    if(your=='Y'){
      score+=6;
    }
    if(your=='Z'){
      score+=0;
    }
  }
  if(opp=='B'){
    if(your=='X'){
      score+=0;
    }
    if(your=='Y'){
      score+=3;
    }
    if(your=='Z'){
      score+=6;
    }
  }
  if(opp=='C'){
    if(your=='X'){
      score+=6;
    }
    if(your=='Y'){
      score+=0;
    }
    if(your=='Z'){
      score+=3;
    }
  }
  if(your=='X'){
    score+=1;
  }else if(your=='Y'){
    score+=2;
  }else{
    score+=3;
  }
    return 0;
}
