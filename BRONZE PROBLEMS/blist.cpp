#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;
int cows[100][1000];
int cowamount[100];
int main(){
    ifstream cin("blist.in");
    ofstream cout("blist.out");
    int n;
    cin>> n;
    int maxbuckets=0;
    int totalbuckets=0;
    int a,b,c;
    int maximum=0;
    for(int i=0; i<n; i++){
        cin>> a>>b>>c;
        cows[i][a]=c;
        cows[i][b]=(-1*c);
        maximum= max(maximum,b);
    }
    for(int i=1; i<maximum; i++){
        totalbuckets=0;
        for(int j=0; j<n; j++){
            cowamount[j]=cowamount[j]+cows[j][i];
            totalbuckets=totalbuckets+cowamount[j];
        }
            maxbuckets=max(maxbuckets,totalbuckets);
    }
cout<< maxbuckets;

    return 0;
}
