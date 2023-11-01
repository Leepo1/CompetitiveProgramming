#include <iostream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <string>

using namespace std;

int main(){
int t;
cin>> t;
string s;
for(int i=0; i<t; i++){
cin>> s;
int l=s.size();
for(int j=0; j<l; j++){
    if(s[j]=='E'){
        cout<< "CW" << endl;
        break;
    } else if(s[j]=='W'){
        cout<< "CCW" << endl;
        break;
    }
} 



}

}