#include <iostream>
#include <algorithm>
#include <cmath>
#include <math.h>

using namespace std;

int main(){
    int n;
    cin>> n;
    int petal[n];
    int averagecount=0;
    int petalcount=0;
    for(int i=0; i<n; i++){
        cin>> petal[i];
    }
    for(int i=0; i<n; i++){
        petalcount=0;
        for(int j=i; j<n; j++){
            petalcount=petalcount+petal[j];
            for(int g=i; g<=j; g++){
                if(petalcount%(j-i+1)==0 && petal[g]==petalcount/(j-i+1)){
                    averagecount=averagecount+1;
                    break;
                }
            }
        }
    }

    cout<< averagecount;




    return 0;
}