#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int main(){
  ifstream cin("AdventofCodeDay2.in");
  ofstream cout("AdventofCodeDay2.out");
    int arr[3];
    arr[0]=0;
    arr[1]=0;
    arr[2]=0;
    string s;
    int x;
    while(cin>>s){
      if(s=="forward"){
        cin>>x;
        arr[0]=arr[0]+x;
        arr[2]=arr[2]+x*arr[1];
      } else if(s=="down"){
        cin>>x;
        arr[1]=arr[1]+x;
      }else if(s=="up"){
        cin>>x;
        arr[1]=arr[1]-x;
      }
    }
    cout<< arr[0]*arr[2];
    return 0;

}
