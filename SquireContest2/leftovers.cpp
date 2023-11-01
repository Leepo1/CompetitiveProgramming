#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
ll lcm(ll a, ll b){
    return a*b/(gcd(a,b));
}
int main(){
    ll t; cin >> t;
    while(t--){
        long long a,b,c,d;
        char trash;
        cin>> a >> trash >> b >> c >> trash >> d;
        ll num = a*lcm(b,d)/b + c*(lcm(b,d))/d;
        ll denom = lcm(b,d);
        cout << num/gcd(num,denom) << "/" << denom/gcd(num,denom) << '\n';
    }


    return 0;
}