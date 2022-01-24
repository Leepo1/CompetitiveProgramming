#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
using namespace std;
map<string,int> m;
map<int,string> gm;
void checkbasic(string s){
  if(s.size()==2){
    m[s]=1;
    gm[1]=s;

  }else if(s.size()==4){
    m[s]=4;
    gm[4]=s;

  }else if(s.size()==3){
    m[s]=7;
    gm[7]=s;

  }else if(s.size()==7){
    m[s]=8;
    gm[8]=s;

  }

}
int main(){
  ifstream cin("AdventofCodeDay8.in");
  ofstream cout("AdventofCodeDay8.out");

  string s;

  long long sum=0;
  for(int q=0; q<200; q++){
    long long minisum=0;
      m.clear();
      gm.clear();
      string arr[10];
    for(int i=0; i<10; i++){
      cin>>s;
      sort(s.begin(),s.end());
  checkbasic(s);
      arr[i]=s;
    }

    for(int i=0; i<10; i++){
      if(arr[i].size()==5){
        int check=0;
        for(int j=0; j<5; j++){
          if(arr[i][j]==gm[1][0] || arr[i][j]==gm[1][1]){
            check=check+1;
          }
        }
          if(check==2){
            m[arr[i]]=3;
          }else {
            check=0;
            for(int j=0; j<5; j++){
                if(arr[i][j]==gm[4][0] || arr[i][j]==gm[4][1] || arr[i][j]==gm[4][2] || arr[i][j]==gm[4][3]){
                  check=check+1;
                }
            }
            if(check==3){
              m[arr[i]]=5;
            }else{
              m[arr[i]]=2;
            }
          }
      }else if(arr[i].size()==6){
        int check=0;
        for(int j=0; j<6; j++){
          if(arr[i][j]==gm[1][0] || arr[i][j]==gm[1][1]){
            check=check+1;
          }
        }
        if(check==1){
          m[arr[i]]=6;
        }else{
          check=0;
          for(int j=0; j<6; j++){
            if(arr[i][j]==gm[4][0] || arr[i][j]==gm[4][1] || arr[i][j]== gm[4][2] || arr[i][j]==gm[4][3]){
              check=check+1;
            }
          }
          if(check==4){
            m[arr[i]]=9;
          }else{
            m[arr[i]]=0;
          }
        }
      }
    }
cin>>s;
   for(int i=0; i<4; i++){
      cin>> s;
      sort(s.begin(),s.end());
      minisum= minisum*10+m[s];
      }
    sum=sum+minisum;
    }
cout<< sum;
    return 0;
}
