#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
  ifstream cin("lostcow.in");
  ofstream cout("lostcow.out");
    int x,y;
    cin>> x >> y;
    bool direction=true;
    int distance=1;
    int spot=x;
    int traveled=0;

    while(true){

      if((direction && y-x>=0 && y-x<=distance) || (!direction && x-y<=distance && x-y>=0)){

        traveled+= abs(y-spot);
        cout<< traveled;
        return 0;

      }else {
        int oldspot=spot;
        if(direction){
          spot= x+ distance;
        }else{
          spot= x- distance;
        }

        traveled+= abs(spot-oldspot);

        distance*=2;

        direction= !direction;
      }

    }

    return 0;
}
