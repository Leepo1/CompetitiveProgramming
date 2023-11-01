/*
ID: Sameer Bhatti 
Grade:8
Task:
LANG: C++11
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <utility>
#define INF 2000000000
using namespace std;
#define pii pair<int, pair<int,int>>
#define pi pair<int,int>

int main (){

ifstream cin ("socdist1.in");
ofstream cout ("socdist1.out");
int l;
cin>> l;
string s;
cin>> s;
vector<int> v;
int distance=0;
for(int i=0; i<l; i++){
 if(s[i]=='1'){
     if(i==0){
         continue;
     }else{
     v.push_back(distance);
     distance=0;
     }
 }
 else{
     distance=distance+1;
 }
} 
    int vsize= v.size();
    sort(v.begin(),v.end());
    
    for(int i=0; i<2; i++){
       int large=v[vsize-1];
        v.erase(v.begin()+vsize-1);
        if(large%2==0){
    v.push_back(large/2-1);
    v.push_back(large/2);
        }else{
            v.push_back((large-1)/2);
            v.push_back((large-1)/2);
        }
        vsize=v.size();
        
    sort(v.begin(),v.end());
    
    }
for(int j=0; j<vsize; j++){
    v[j]=v[j]+1;
    }
cout<< v[0];




return 0;

}