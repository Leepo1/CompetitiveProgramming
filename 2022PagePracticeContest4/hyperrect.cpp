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

map<int,int> m;
int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  cout.tie(0);
  //ifstream cin("hyperrecti.txt");
  //ofstream cout("hyperrecto.txt");
  int c;
  cin>> c;
  while(c--){

    m.clear();
    int n;
    cin>> n;
    int arr[n];
    for(int i=0; i<n; i++){
      cin>> arr[i];
      m[arr[i]]++;
    }
    sort(arr,arr+n);
    vector<int> v;


    for(int i=0; i<n; i++){
      if(m[arr[i]]>=2){
            v.push_back(arr[i]);
            m[arr[i]]-=2;
      }
    }
    sort(v.begin(),v.end());

      if(v.empty() || v.size()==1){
        cout<< arr[n-1] << '\n';
      }else{
        int answer= max(v[v.size()-1]*v[v.size()-2], arr[n-1]);
        cout<< answer << '\n';
      }
  }

    return 0;
}
