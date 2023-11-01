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
#include <stack>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;


int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  cout.tie(0);
  //ifstream cin("traveli.txt");
  //ofstream cout("travelo.txt");
  int c;
  cin>> c;
  while(c--){
    vector<int> v;
    int n,k;
    cin>> n >> k;
    string s;
    cin>> s;
    int l= s.size();
    int arr[l];
    for(int i=0; i<l; i++){
      arr[i]= s[i]- '0';
    }

    for(int i=0; i<l; i++){

        while(true){
          if(v.empty()){
            v.push_back(arr[i]);
            break;
          }
          if(v.back()<arr[i]){
            if(v.size()-1+((l-1-i)+1)>=k){
              v.pop_back();
            }else{
              v.push_back(arr[i]);
              break;
            }
          }else{
            if(v.size()==k){
              break;
            }else{
              v.push_back(arr[i]);
              break;
          }

          }

        }

    }
    int temp=v.size();
    for(int i=0; i<k; i++){
      cout<< v[i];

    }
    cout<< endl;

  }



    return 0;
}
