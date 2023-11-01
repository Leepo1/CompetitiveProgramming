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
    ifstream cin("photo.in");
    ofstream cout("photo.out");
    string s;
    cin>> s;
    cout<< s;
    /*int n;
    cin>> n;
    int b[n-1];
    int arr[n];
    int count;
    for(int i=0; i<n-1; i++){
      cin>> b[i];
    }
    for(int i=1; i<b[0]; i++){
      arr[0]=b[0]-i;
      for(int j=1; j<n; j++){
        arr[j]=b[j-1]-arr[j-1];
      }
      sort(arr ,arr +n);
      for(int j=0; j<n; j++){
        if(arr[j]==j+1){
          count=count+1;
        }
      }
      if(count==n){
        for(int j=0; j<n; j++){
          cout<< arr[i

          cout<< "NIcholas";] << " ";
        }
      }
    }
*/
    return 0;
}
