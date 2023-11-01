#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 1e9 + 7;
vector<ll> prime_factorization(ll a) {
    vector<ll> temp;
    ll curr = 2;
    while (curr*curr <= a) {
        ll power = 0;
        while (a%curr == 0) {
            power++; a /= curr;
        }
        curr++;
        if(power == 0) continue;
        temp.push_back(power);
    }
    if (a>1) temp.push_back(1);
    return temp;
}

int main(){
    int t; cin>> t;
    while(t--){
        ll a,b;
        cin>> a >> b;
        ll answer = 1;
        vector<ll> newpowers = prime_factorization(a);
        for(int i = 0; i < newpowers.size(); i++){
            newpowers[i] = (newpowers[i]*b)%(mod);
        }
        for(auto u : newpowers){
            answer = (answer * (u + 2)*(u + 1)/2)%(mod);
        }
        cout<< answer << '\n';
    }
}