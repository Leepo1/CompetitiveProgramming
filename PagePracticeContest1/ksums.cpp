#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
using namespace std;
map<int,vector<long long>> window;
int main(){
  //ifstream cin("ksumsi.txt");
  //ofstream cout("ksumso.txt");
  int c;
  cin>> c;
  while(c--){
    window.clear();
    long long n;
    int k;
    cin>> n >> k;
    int arr[n];
    long long prefix[n+1];
    prefix[0]=0;
    for(int i=0; i<n; i++){
      cin>> arr[i];
    }
    for(int i=1; i<=n; i++){
      prefix[i]=prefix[i-1]+arr[i-1];
    }

    int index=1;
    vector<long long> v;
    for(int i=k; i<=n; i++){
      long long a= prefix[i]-prefix[i-k];
      if(window[a].empty()){
        v.push_back(a);
      }
      window[a].push_back(index);
      index++;
    }

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    for(auto u : v){
      sort(window[u].begin(),window[u].end());
      for(auto b : window[u]){
        cout<< b << " ";
      }
    }
    cout<< '\n';
  }


  return 0;
}
