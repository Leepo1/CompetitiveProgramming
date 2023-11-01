#include <iostream>

using namespace std;
bool visited[200005];
int main(){
  int n;
  cin>> n;
  for(int i=0; i<n-1; i++){
    int a;
    cin>> a;
    visited[a]=true;
  }
  for(int i=1; i<n+1; i++){
    if(!visited[i]){
      cout<< i;
      return 0;
    }
  }


  return 0;
}
