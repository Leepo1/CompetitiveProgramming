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



int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  cout.tie(0);
  //ifstream cin("ai.txt");
  //ofstream cout("ao.txt");
  int t;
  cin>> t;
  while(t--){
    int n,m;
    cin>> n >> m;
    int arr[n];
    bool visited[m];
    for(int i=0; i<m; i++){
      visited[i]=false;
    }
    for(int i=0; i<n; i++){
      cin>> arr[i];
    }
    for(int i=0; i<n; i++){
      int place= min(arr[i]-1,(m+1)-arr[i]-1);
      int other= max(arr[i]-1,(m+1)-arr[i]-1);
      if(visited[place]){
        visited[other]=true;
      }else{
        visited[place]=true;
      }
      //visited[arr[i]-1]=true;
      //visited[(m+1)-arr[i]-1]=true;
    }
    string answer="";
    for(int i=0; i<m; i++){
      if(visited[i]){
        answer+='A';
      }else{
        answer+='B';
      }
    }
    cout<< answer << '\n';
  }

    return 0;
}
