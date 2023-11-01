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
     ifstream cin("gymnastics.in");
    ofstream cout("gymnastics.out");
 int k,n;
 cin>> k>>n;
 map<pii , int> m;
 int g=0;
 int count=0;
 int ans=0;

        for(int a=0; a<k; a++){
            for(int b=0; b<n; b++){
                cin>> g;
                m[make_pair(k,g)]=b;
            }
        }
       for(int i=0; i<n; i++){
           for(int j=i+1; j<n; j++){
               for(int a=0; a<k; a++){
                   int count=0;
                   if(m[]>arr[k][j]){
                       count=count+1;
                   }
    
               }
                if(count==k){
                       ans=ans+1;
                   }
           }
       }
       cout<< ans;
    return 0;
}