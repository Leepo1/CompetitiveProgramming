#include <iostream>
#include <algorithm>
#include <cmath>
#include <math.h>

using namespace std;

int main(){
    int n,k;
    cin>> n>>k;
    int place[n+1][k+1];
    int consistency[k+1][k+1];
    int a;
    int count=0;
    for(int i=1; i<n+1; i++){
        for( int j=1; j<k+1; j++){
            cin>>a;
            place[a][i]=k+1-j;
        }
    }
    for(int j=1; j<n+1; j++){
    for(int i=1; i<k+1; i++){
            for(int w=1; w<k+1; w++){
                if(place[i][j]>place[w][j]){
                    consistency[i][w]=consistency[i][w]+1; 
                } else {
                    consistency[w][i]=consistency[w][i]+1;
                }

            }
    }
    }
for(int i=1; i<k+1; i++){
    for(int w=1; w<k+1; w++)
if(consistency[i][w]==4){
    count=count +1;
}
}
cout<< count;


}