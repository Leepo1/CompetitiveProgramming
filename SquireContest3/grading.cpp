#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll fact[1000005];
long long derange[1000005];
const long long mod = 1e9 + 7;
int main(){
    //ifstream cin("input");
    //ofstream cout("output");
    fact[1] = 1;
    derange[1] = 0;
    derange[2] = 1;
    for(long long i = 2; i < 1000005; i++){
        fact[i] = (i * fact[i-1]) % mod;
        derange[i] = (i*derange[i-1]) % mod;
        if(i%2==0) derange[i] = (derange[i] + 1) % mod;
        else derange[i] = (derange[i] - 1) % mod;
    }
    long long t; cin>> t;
    while(t--){
        long long n; cin >> n;
        cout << derange[n] << '\n';
    }
    return 0;
}