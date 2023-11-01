#include <bits/stdc++.h>
using namespace std;
map<char,int> freq;
int main(){
    int t; cin>> t;
    while(t--){
        freq.clear();
        int amount = 0;
        string s; cin>> s;
        set<char> c;
        for(int i = 0; i < s.size(); i++){
            c.insert(s[i]);
            freq[s[i]]++;
        }
        if(freq['e'] == 0){
            cout<< "impossibleeee" << '\n';
            continue;
        }
        for(auto u : c){
            if(u == 'e') continue;
            if(freq[u] >= freq['e']){
                amount += (freq[u] - (freq['e']- 1));
            }
        }
        cout<< amount << '\n';
    }
}