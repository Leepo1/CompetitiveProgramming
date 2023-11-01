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
 ll n;
 string s;

 cin>> n;
 cin>>s;
 ll throwcount=0;
 for(ll i=0; i<n-2; i++){
   ll gcount=0;
   ll hcount=0;
   for(ll j=0; j<3; j++){
     if(s[i+j]=='G'){
       gcount++;
     }else {
       hcount++;
     }
   }
   if(hcount==1 || gcount ==1){
     throwcount++;
   }
   for(ll j=3; j<n-i; j++){
     if(s[i+j]=='G'){
       gcount++;
     }else {
       hcount++;
     }
     if(gcount==1 || hcount==1){
       throwcount++;
     }else if(gcount>1 && hcount>1){
       break;
     }
   }

 }
cout<< throwcount <<'\n';
    return 0;
}
