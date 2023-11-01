#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
queue<int> q;
bool checks(int k, int a){
    int t=-1;
    int check;
    int arr[k];
    while(true){
        if(t==-1){
            for(int i=0; i<k; i++){
                arr[i]=q.front();
                q.pop();
            }
        }
        for(int i=0; i<k; i++){
            check=0;
            arr[i]=arr[i]-1;
            if(arr[i]==0){
                if(q.empty()){
                    continue;
                } else{
                arr[i]=q.front();
                q.pop();
                }
            }
            if(arr[i]<=0){
                check=check+1;
            }
        }
        t=t+1;
        if(check==k){
            break;
        }
    }
        if(t<=a){
            return true;
        } else {
            return false;
        }
}

int main(){
    ifstream cin("cowdance.in");
    ofstream cout("cowdance.out");
    int n, a;
    cin>> n>> a; 
    int x;
int ans;
    for(int i=0; i<n; i++){
        cin>> x;
        q.push(x);
    }
    int l=0; int r=100000;
    while(l<=r){
        int mid= l+(r-l)/2;
        if(checks(mid,a)){
            r=mid-1;
            ans=mid;
        }else{
            l=mid+1;
        }
    }
    

    return 0;
}