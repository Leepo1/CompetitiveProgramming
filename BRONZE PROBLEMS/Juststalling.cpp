#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
  int n;
int stalls[20];
int cows[20];
int  nstall(int a){
    int cnt=0;
    for(int g=0; g<n; g++){
        if(a>=stalls[g]){
            cnt=cnt+1;
        }
    }
    return cnt;
}
int main(){
    cin >> n;
    long long answer=1;
   
    for(int i=0; i<n; i++){
        cin>> cows[i];
    }
    for(int i=0; i<n; i++){
        cin>> stalls[i];
    }
        sort(cows, cows+n);
        sort(stalls, stalls+n);
        for(int i=n-1; i>-0; i--){
            answer=answer*(nstall(cows[i])-(n-1-i));
        }
        cout<< answer;
    return 0;
}