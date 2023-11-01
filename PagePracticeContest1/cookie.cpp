#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main(){
  //ifstream cin("cookiei.txt");
  //ofstream cout("cookieo.txt");
  int c;
  cin>> c;
  while(c--){
    long long cc, s, o, p;
    cin>> cc >> s >> o >> p;
    long long arr[3];

    arr[0]=cc;
    arr[1]=s;
    arr[2]=o;
    sort(arr,arr+3);



    p=p-arr[0];
    arr[1]=arr[1]-arr[0];
    arr[0]=0;

    p=p-arr[1];
    arr[2]=arr[2]-arr[1];
    arr[1]=0;

    if(p<=0){
      cout<< 0 << '\n';
    }else {
      cout<< p << '\n';
    }

  }
  return 0;
}
