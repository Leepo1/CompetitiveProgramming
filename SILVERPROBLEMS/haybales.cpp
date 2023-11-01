#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main(){
    ifstream cin("haybales.in");
    ofstream cout("haybales.out");
    int n,q;
    cin>> n>>q;
    vector<int> v;
    int x;
    for(int i=0; i<n; i++){
        cin>> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(int i=0; i<q; i++){
        int y;
        cin>>x>>y;
        cout<< upper_bound(v.begin(), v.end(),y) - lower_bound(v.begin(), v.end(), x) << endl;
    }

    return 0;
}
