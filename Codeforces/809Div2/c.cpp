#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <iomanip>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;


int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  cout.tie(0);
  //ifstream cin("ci.txt");
  //ofstream cout("co.txt");
  int t;
  cin>> t;

  while(t--){
    int n;
    cin>> n;
    int arr[n];
    for(int i=0; i<n; i++){
      cin>> arr[i];
    }
    int begin=0;
    for(int i=1; i<n-1; i++){
      int number= max(arr[i-1],arr[i+1]);
      if(arr[i]>number){
        begin++;
      }
    }

    int cost=0;
    if(n%2==1){
      for(int i=1; i<=n-2; i+=2){
        int number= max(arr[i-1],arr[i+1]);
        if(arr[i]>number){
          continue;
        }else{
          cost+= (number-arr[i])+1;
        }
      }
      if(begin==(n/2)){
        cost=0;
      }
    }else{
      int tc=0;
      //situation 1
      for(int i=1; i<=n-3; i+=2){
        int number= max(arr[i-1],arr[i+1]);
        if(arr[i]>number){
          continue;
        }else{
          tc+= (number-arr[i])+1;
        }
      }
      //cout << tc << " ";
      // situation 2
      int ttc=0;
      for(int i=2; i<=n-2; i+=2){
        int number= max(arr[i-1],arr[i+1]);
        if(arr[i]>number){
          continue;
        }else{
          ttc+= (number-arr[i])+1;
        }
      }

      cost+= min(tc,ttc);
      if(begin==(n/2)-1){
        cost=0;
      }
    }

    cout<< cost << '\n';
  }

    return 0;
}
