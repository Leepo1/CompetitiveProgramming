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
  //ifstream cin("ParrotRiddlesi.txt");
  //ofstream cin("ParrotRiddleso.txt");
  int arr[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
  int num=0;
  for(int i : arr){
    cout<< "?" << " " << i << '\n';
    string ans;
    cin>> ans;
    if(ans=="yes"){
      num++;
      if(i<10){
        cout<< "? " << i*i << '\n';
        cin>> ans;
        if(ans=="yes"){
          cout<< "! composite";
          return 0;
          num++;
        }
      }
      if(num>=2){
        cout<< "! composite";
        return 0;
      }
    }
  }
  cout<< "! prime";
    return 0;
}
