#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
  //ifstream cin("snoozei.txt");
  //ofstream cout("snoozeo.txt");
  int c;
  cin>> c;
  while(c--){
    long long n,l;
    cin>> n >>l;
    vector<long long> a(n);

    for(int i=0; i<n; i++){
      cin>> a[i];
    }
    sort(a.begin(),a.end());
    vector<long long> v(n-1);
    for(int i=1; i<n; i++){
      v[i-1]=a[i]-a[i-1]-1;
    }
    sort(v.begin(),v.end());
    long long answer=0;
    for(int i=0; i<(n-1); i++){
      answer=max(answer,v[i]*(n-1-i));
    }
    cout<< answer << '\n';
  }
  return 0;
}
