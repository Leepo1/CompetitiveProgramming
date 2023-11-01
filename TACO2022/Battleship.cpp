#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;


int main(){

  int n;
  int x,y;
  cin>> n >> x >> y;
  char arr[n][n];
  char c;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin>> arr[i][j];
    }
  }
  if(arr[x][y]=='S'){
    cout<< "No";
  }else{
    cout<< "Yes";
  }

return 0;
}
