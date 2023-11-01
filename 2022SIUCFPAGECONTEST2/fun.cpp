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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  //ifstream cin("funi.txt");
  //ofstream cout("funo.txt");
  int c;
  cin >> c;
  while(c--){
    int n;
    cin >> n;
    int arr[n][2];
    int answer=0;
    bool group1=false;
    bool group2=false;
    int index;
    int curr=100000;
    for(int i=0; i<n; i++){

      cin>> arr[i][0] >> arr[i][1];
      if(max(arr[i][0],arr[i][1])==arr[i][0]){
        group1=true;
      }else if(max(arr[i][0],arr[i][1])==arr[i][1]){
        group2=true;
      }
      if(abs(arr[i][1]-arr[i][0])<curr){
        curr= abs(arr[i][1]-arr[i][0]);
        index=i;
      }

    }

    if(group1 && group2){
      for(int i=0; i<n; i++){
        answer+=max(arr[i][0],arr[i][1]);
      }
    }else{
      for(int i=0; i<n; i++){
        if(i!=index){
          answer+=max(arr[i][0],arr[i][1]);
        }else{
          answer+=min(arr[i][0],arr[i][1]);
        }
      }
    }


    cout<< answer << '\n';
  }



    return 0;
}
