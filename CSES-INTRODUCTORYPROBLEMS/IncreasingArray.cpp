#include <iostream>

using namespace std;

int main(){
  long long n;
  cin>> n;
  long long cost=0;
  long long prev;
  long long curr;
  for(int i=0; i<n; i++){
    if(i==0){
      cin>> prev;
      continue;
    }
    cin>> curr;
    if(prev>=curr){
      cost+=prev-curr;
      curr=prev;
    }
    prev=curr;
  }
  cout<< cost;
  return 0;
}
