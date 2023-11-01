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
int n,k;
vector<int> v;

bool works(int r){
    int current=0;
    int numb=0;
    while(current<n){
    current= (upper_bound(v.begin(), v.end(), v[current] +2*r)-v.begin());
    numb=numb+1;
    }
    if(numb>k){
        return false;
    } else {
        return true;
    }
    
}
int main(){
    
    cin>> n>>k;
    int ans;
    int x;
    for(int i=0; i<n; i++){
       cin>> x;
       v.push_back(x);
    }
    sort(v.begin(), v.end());
    int l, r= n/2+1;
    while(l<=r){
        int mid= l + (r-l)/2;
        if(works(mid)){
            ans=mid;
            r=mid-1;
        } else {
            l=mid+1;
        }

    }
    cout<< ans;
    return 0;
}