#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int n,x;
  cin>> n >> x;
  int c[n];
  for(int i=0; i<n; i++){
    cin>> c[i];
  }
  sort(c,c+n);
  int l=0;
  int r=n-1;
  int number=0;
  while(l<=r){
    if(c[l]+c[r]<=x){
      l++;
      r--;
    }else {
      r--;
    }
    number++;
  }

  cout<< number << '\n';

  return 0;
}
