#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
using namespace std;
int arr[5][5];
bool brr[5][5];
bool checkifwon(bool brr[5][5]){
  for(int i=0; i<5; i++){
    if(brr[i][0]==true && brr[i][1]==true && brr[i][2]==true && brr[i][3]==true && brr[i][4]==true){
      return true;
    } else if(brr[0][i]==true && brr[1][i]==true && brr[2][i]==true && brr[3][i]==true && brr[4][i]==true){
      return true;
  }
}
    return false;
}
int boardscore(bool brr[5][5]){
  int curr=0;
  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
      if(brr[i][j]==false){
        curr=curr+arr[i][j];
      }
    }
  }
  return curr;
}
int main(){
  ifstream cin("AdventofCodeDay4.in");
  ofstream cout("AdventofCodeDay4.out");
  vector<int> v;
  int x;
  char c;

   for(int i=0; i<100; i++){
     cin>>x;
     v.push_back(x);
     if(i!=99){
     cin>> c;
   }
   }
   int max=0;
   int score=0;
   for(int g=0; g<100; g++){
   for(int i=0; i<5; i++){
     for(int j=0; j<5; j++){
       cin>> arr[i][j];
       brr[i][j]=false;
     }
   }
   for(int n=0; n<v.size(); n++){
     for(int i=0; i<5; i++){
       for(int j=0; j<5; j++){
        if(v[n]==arr[i][j]){
          brr[i][j]=true;
        }
       }
     }
     if(checkifwon(brr)==true){
       if(n>=max){
       max=n;
       score= v[n]*boardscore(brr);
       cout<< score << endl;
     }
     break;
     }
   }
 }

     return 0;
 }
