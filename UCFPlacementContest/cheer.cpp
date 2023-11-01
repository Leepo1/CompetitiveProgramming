#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int main(){
  //ifstream cin("cheeri.txt");
  //ofstream cout("cheero.txt");
  long long t;
  cin>> t;
  while(t--){
    long long n;
    cin >> n;
    long long arr[n];
    for(long long i=0; i<n; i++){
      cin>> arr[i];
    }
    sort(arr,arr+n);
    long long answer=arr[n-1];
    long long curr=arr[n-1];
    for(long long i=n-2; i>=0; i--){
      if(arr[i]+2<=curr){
        answer+= arr[i];
        curr=arr[i];
      }
    }
    cout<< answer << '\n';
  }
}
