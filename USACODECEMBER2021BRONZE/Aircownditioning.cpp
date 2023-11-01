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
  int n;
  cin>>n;
  int ideal[n];
  int actual[n];
  int difference[n];

  for (int i=0; i<n; i++){
    cin>> ideal[i];
  }
  for (int i=0; i<n; i++){
    cin>> actual[i];
    difference[i]=ideal[i]-actual[i];
  }
  int start;
  int end;
  int steps=0;



    // BAD/DUNNO if will always work solutiom
    while(true){
    for(int i=0; i<n; i++){
      if(difference[i]>0){
        start =i;
        end=i;
        for(int j=1; j<n-i; j++){
          if(difference[i+j]>0){
            end=i+j;
          }else{
            break;
          }
        }
          for(int j=start; j<end+1; j++){
            actual[j]++;
          }
          steps++;
          break;
      } else if(difference[i]<0){
          start =i;
          end=i;
          for(int j=1; j<n-i; j++){
            if(difference[i+j]<0){
              end=i+j;
            }else {
              break;
            }
          }
          for(int j=start; j<end+1; j++){
            actual[j]--;
          }
          steps++;
          break;
      }
    }
    bool a=true;
    for(int i=0; i<n; i++){
      difference[i]=ideal[i]-actual[i];
      if(difference[i]!=0){
        a=false;
      }
    }
    if(a){
      break;
    }
  }
cout<< steps;

    return 0;
}
