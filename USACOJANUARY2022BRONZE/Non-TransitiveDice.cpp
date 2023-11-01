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
int A[4];
int B[4];
int C[4];
int awinner(){
  int acount=0;
  int ccount=0;
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
        if(A[i]>C[j]){
          acount++;
        }else if(A[i]<C[j]){
          ccount++;
        }
      }
  }
  if(ccount>acount){
    return 1;
  }else if(acount>ccount){
    return 0;
  }else {
    return -1;
  }

}

int bwinner(){
  int bcount=0;
  int ccount=0;
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
    if(B[i]>C[j]){
          bcount++;
        }else if(B[i]<C[j]){
          ccount++;
        }
      }
  }
  if(ccount>bcount){
    return 1;
  }else if(bcount>ccount){
    return 0;
  }else {
    return -1;
  }
}

int main(){

  int t;
  cin>> t;
  for(int q=0; q<t; q++){
    int awins=0;
    int bwins=0;
    int cwins=0;
    for(int i=0; i<4; i++){
      cin>> A[i];
    }
    for(int i=0; i<4; i++){
      cin>> B[i];
    }
    int as=0;
    int bs=0;
    for(int i=0; i<4; i++){
      for(int j=0; j<4; j++){
          if(A[i]>B[j]){
            as++;
          }else if(A[i]<B[j]){
            bs++;
          }
        }
  }
  if(as==bs){
    cout<< "no" << endl;
    continue;
  }else if(as>bs){
    awins++;
  }else {
    bwins++;
  }

  bool stop=false;
  for(int a=1; a<=10; a++){
    C[0]=a;
    if(stop==true) break;

    for(int b=1; b<=10; b++){
      C[1]=b;
      if(stop==true) break;

      for(int c=1; c<=10; c++){
        C[2]=c;
        if(stop==true) break;

        for(int d=1; d<=10; d++){
          int tawins=awins;
          int tbwins=bwins;
          cwins=0;
          C[3]=d;
          if(stop==true) break;

          if(awinner()==-1 || bwinner() ==-1){
            continue;
          }

          if(awinner()==1){
            cwins++;
          }else if(awinner()==0){
            tawins++;
          }
          if(bwinner()==1){
            cwins++;
          }else if(bwinner()==0){
            tbwins++;
          }
            if(tawins==1 && tbwins==1 && cwins==1){
              cout<< "yes"<< endl;
              stop=true;
              break;
            }
        }
      }
    }
  }
  if(stop==true){
    continue;
  }
  cout<< "no" << endl;
}
    return 0;
}
