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
    ifstream cin("socdist2.in");
    ofstream cout("socdist2.out");
    int n;
    cin>> n;
    int arr[n];
    vector<int> v;
    map<int,bool> psn;
    int a;
    int groups=1;

    for(int i=0; i<n; i++){
      fin>> arr[i];
      fin>> a;
      if(a==1){
        psn[arr[i]]=true;
      } else{
        psn[arr[i]]=false;
      }
    }

    sort(arr, arr+n);

    int maximum=arr[n-1]-arr[0];
    for(int i=0; i<n-1; i++){
      if(psn[arr[i]]!=psn[arr[i+1]]){
        maximum= min(maximum,arr[i+1]-arr[i]-1);

      }

    }
    for(int i=0; i<n; i++){
      if(psn[arr[i]]==true){
        v.push_back(arr[i]);
      }
    }
    for(int i=0; i<n-1; i++){
      if(v[i+1]-v[i]<=maximum){
        continue;
      }else{
        groups=groups+1;
      }
    }
    cout<< groups << endl;
    return 0;
}
