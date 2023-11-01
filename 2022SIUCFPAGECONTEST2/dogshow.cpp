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
int ih, iw,ij, ic;
struct dog{
  string name;
  int h,w,j,c;
};

bool cmp(dog &a, dog &b){
  if(abs(ih-a.h)==abs(ih-b.h)){
    if(abs(iw-a.w)==abs(iw-b.w)){
      if(abs(ij-a.j)==abs(ij-b.j)){
        if(abs(ic-a.c)==abs(ic-b.c)){
          return a.name<b.name;
        }
        return abs(ic-a.c)<abs(ic-b.c);
      }
      return abs(ij-a.j)<abs(ij-b.j);
    }
    return abs(iw-a.w)<abs(iw-b.w);
  }
  return abs(ih-a.h)<abs(ih-b.h);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  //ifstream cin("dogshowi.txt");
  //ofstream cout("dogshowo.txt");
  int c;
  cin>> c;

  while(c--){

    cin >> ih >> iw >> ij >> ic;
    int n;
    cin>> n;
    dog arr[n];
    for(int i=0; i<n; i++){
      cin>> arr[i].name >> arr[i].h >> arr[i].w >> arr[i].j >> arr[i].c;
    }
      sort(arr,arr+n,cmp);
      for(int i=0; i<n; i++){
      cout<< arr[i].name << '\n';
    }

  }

    return 0;
}
