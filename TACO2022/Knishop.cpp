#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

bool oneknightmove(long long x, long long y, long long x1, long long y1){
  if((x1==x+2 && y1==y+1) || (x1==x+2 && y1==y-1) || (x1==x-2 && y1==y+1) || (x1==x-2 && y1==y-1) || (x1==x+1 && y1==y+2) || (x1==x+1 && y1==y-2) || (x1==x-1 && y1==y+2) || (x1==x-1 && y1==y-2)) {
    return true;
  }

    return false;


}

bool diagonol(long long x, long long y, long long x1, long long y1){
  if(abs(x-x1)==abs(y-y1)){
    return true;
  }
    return false;
  }
int main(){


  //ifstream cin("Knishopi.txt");
  //ofstream cout("Knishopo.txt");

  long long x,y,x1,y1;
  cin>> x >> y >> x1 >> y1;
  bool p,p1;

  if(abs(x+y)%2==1){
    p=true;
  }else {
    p=false;
  }

  if(abs(x1+y1)%2==1){
    p1=true;
  }else {
    p1=false;
  }

  if(x==x1 && y==y1){
    cout<< 0;
    return 0;
  }else if(oneknightmove(x,y,x1,y1) || diagonol(x,y,x1,y1)){
    cout<< 1;
    return 0;
  }else if(p==p1){
    cout<< 2;
    return 0;
  }else{

    if(diagonol(x+2, y+1, x1, y1)){
      cout<< 2;
      return 0;
    }else if(diagonol(x+2, y-1, x1, y1)){
      cout<< 2;
      return 0;
    } else if(diagonol(x-2, y+1, x1, y1)){
      cout<< 2;
      return 0;
    }else if(diagonol(x-2, y-1, x1, y1)){
      cout<< 2;
      return 0;
    }else if(diagonol(x+1, y+2, x1, y1)){
      cout<< 2;
      return 0;
    }else if(diagonol(x+1, y-2, x1, y1)){
      cout<< 2;
      return 0;
    }else if(diagonol(x-1, y+2, x1, y1)){
      cout<< 2;
      return 0;
    }else if(diagonol(x-1, y-2, x1, y1)){
      cout<< 2;
      return 0;
    }else {
      cout<< 3;
      return 0;
    }
  }



return 0;
}
