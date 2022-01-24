#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

bool simulate(int x, int y){
  int xpos=0;
  int ypos=0;
  for(int i=0; i<1000; i++){
  xpos+=x;
  ypos+=y;
  if(48<=xpos && xpos<=70 && -189<=ypos && ypos<=-148){
    return true;
  }
    if(x<0){
      x=x+1;
    }else if(x>0){
      x=x-1;
    }
    y--;
  }
  return false;
}
int main(){
int result=0;
/*
target area: x=48..70, y=-189..-148
*/
for(int x=-1000; x<=1000; x++){
    for(int y=-1000; y<=1000; y++){
      if(simulate(x,y)){
        result=result+1;
      }
    }
}


cout<< result;


  return 0;
}
