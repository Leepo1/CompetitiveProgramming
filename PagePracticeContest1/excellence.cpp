#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main(){
  //ifstream cin("excellencei.txt");
  //ofstream cout("excellenceo.txt");
  int c;
  cin>> c;
  while(c--){

    int n;
    cin>> n;
    int arr[n];

    for(int i=0; i<n; i++){
      cin>> arr[i];
    }

    sort(arr,arr+n);
    int answer=0;
    int l=0;
    int r=n-1;
    for(int i=0; i<n/2; i++){

      if(answer==0){
        answer=arr[l]+arr[r];
      }else{
        answer= min(answer, arr[l] +arr[r]);
      }
      l++;
      r--;
    }
    cout<< answer << '\n';
  }


  return 0;
}
