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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  //ifstream cin("promotioni.txt");
  //ofstream cout("promotiono.txt");
  int c;
  cin>> c;

  while(c--){
    int n,g;
    cin>> n >> g;
    int arr[n];
    int prefix[n+1];
    prefix[0]=0;
    for(int i=0; i<n; i++){
      cin>> arr[i];
    }
    for(int i=1; i<=n; i++){
      prefix[i]= prefix[i-1]+arr[i-1];
    }

    int windows[g];

    int req[g];

    for(int i=0; i<g; i++){
      cin>> windows[i] >> req[i];
    }

    for(int i=0; i<g; i++){
      int count=0;
      for(int j=windows[i]; j<n; j++){

        int score= prefix[j]-prefix[j-windows[i]];
        if(score>=req[i]*windows[i]){
          count++;
        }
      }
      cout<< count << '\n';
    }

  }

    return 0;
}
