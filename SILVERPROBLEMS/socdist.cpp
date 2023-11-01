#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
bool checkifwork(int d){
    
}
int main(){
    int n,m;
    long long sum=0;;
    cin>>n>>m;
    int x,y;
    set<int> s;
    int z=0;
    for(int i=0; i<m; i++){
        cin>> x>>y;
        for(int j=x; j<=y; j++){
            s.insert(j);
        }
        int l=s.size();
        int arr[l];
       for(set<int>::iterator it = s.begin(); it != s.end(); ++it){
           arr[z]=*it;
           z=z+1;
  }
    for(int i=1; i<l; i++){
        sum=sum+arr[i]-arr[i-1];
    }

    return 0;
    // 0 1 2 3 4 5 6 7 9
}
