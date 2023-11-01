#include #include <iostream>
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
int n,l;
    int ans;
cin>> n>>l;
int arr[n];
bool hindex[n];
for(int i=0; i<n; i++){
    cin>> arr[i];
}
sort(arr, arr+n);
    for(int j=1; j<n; j++){
        int count=0;
    for(int i=0; i<n; i++){
        if(arr[i]>=j){
            count=count+1;
        }
        if(count==j){
            hindex[j]=true;
            break;
        }
    }
        if(count<j){
            break;
        }
    }
    int le=0, r=n;
    while(le<=r){
        int mid= le + (r-le)/2;
        if(hindex[mid]){
            le=mid+1;
            ans=mid;
        }else {
            r=mid-1;
        }
    }
    
        int anumber=0; 
    for(int i=0; i<n; i++){
    
        if(arr[i]==ans){
            anumber=anumber+1;
        }
        if(arr[i]>ans){
            break;
        }
    }
        
    if(number+min(l,anumber)>=ans+1){
        cout<< ans+1;
    }else {
        cout<< ans;
    }
    
    
 
    
    
    
    return 0;
}