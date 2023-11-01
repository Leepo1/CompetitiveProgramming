#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int decoding[200];
int n=0;
void intsfromstring(string a){
    stringstream ss;
    ss << a;
    string number;
    int check;
    while (!ss.eof()) {
        ss >> number;
        if (stringstream(number) >> check){
            decoding[n]= stoi(number);
            n++;
        }
        number = "";
    }
}
int mfn(int a, int b){
  if(a>=0){
    return a%b;
  }else {
    while(a<0){
      a+=b;
    }
    return a;
  }
}
int main(){
  ofstream cout("ACSLCONTEST2.out");
  string ans= "";
    string msg="Python Programming is easier than programming in Java.";
    char key='s';
    int l=msg.size();
    int fibarray[l];
    fibarray[0]=0;
    fibarray[1]=1;
    int shift= int(key);

    for(int i=2; i<msg.size(); i++){
        fibarray[i]=(fibarray[i-1]+fibarray[i-2])%26;

    }

    char option='E';
    if(option=='E'){
    for(int i=0; i<msg.size(); i++){
        if(i%2==0){
            ans= ans+ to_string((mfn(shift-'a'+fibarray[i],26)+'a')*3+ int(msg[i])) + " ";
            }else {
                ans=ans+ to_string((mfn(shift-'a'-fibarray[i],26)+'a')*3 + int(msg[i])) + " ";
            }
          }
    } else{
          intsfromstring(msg);
          for(int i=0; i<n; i++){
            if(i%2==0){
              int num=decoding[i]-3*(mfn(shift-'a'+fibarray[i],26)+'a');
              cout<< char(num);
              }else {
              int num=decoding[i]-3*(mfn(shift-'a'-fibarray[i],26)+'a');
              cout<< char(num);
            }
          }


    }
    cout<< ans;

    return 0;
}
