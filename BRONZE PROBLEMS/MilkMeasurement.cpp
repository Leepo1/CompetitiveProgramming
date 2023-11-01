#include <iostream>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
    map<int,int> b;
    map<int,int> m;
    map<int,int> e;

int main(){
    ifstream cin("measurement.in");
    ofstream cout("measurement.out");
    int n;
    cin>> n;
 
    int x,y;
    string s;
    char c;

    int cb=3, cm=3, ce=3;
    int three[3];
    three[0]=3;
    three[1]=3;
    three[2]=3; 

    int currmax=3;
    int premax=3;
    int pcmcount=3;
    int cmcount=3;
    int maximum=0;

int answer=0;
for(int i=0; i<n; i++){
cin>> x;
cin>> s;
cin>> c;
cin>>y;

if(s=="Bessie"){
    if(c=='-'){
    b[x]= b[x] - y;
    } else {
        b[x]=b[x]+y;
    }
}else if(s=="Mildred"){
    if(c=='-'){
    m[x]= m[x]-y;
    } else {
        b[x]=b[x]+y;
    }
} else if(s=="Elsie"){
    if(c=='-'){
    e[x]= e[x] -y;
    } else {
        e[x]= e[x]+y; 
    }
}
maximum= max(maximum,x);
}

for(int i=0; i<=maximum; i++){
    cb= cb+ b[i];
    cm= cm+ m[i];
    ce= ce+ e[i];
    premax= currmax;
    currmax= max(cb,ce);
    currmax= max(currmax, cm);
    pcmcount=cmcount;
    cmcount=0;
    if(cb==currmax){
        cmcount=cmcount+1;
    } else if(cm==currmax){
        cmcount=cmcount+1;
    } else if(ce==currmax){
        cmcount=cmcount+1;
    }
    
   
    if(currmax!=premax || cmcount!=pcmcount){
        answer=answer +1;
    }
    three[0]=cb;
    three[1]=ce;
    three[2]=cm;
}
cout<< answer;
    return 0;
}