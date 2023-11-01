#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ifstream cin("word.in");
    ofstream cout("word.out");
    int n,k;
    cin>> n>> k;
    int curr=0;
    string words[n];
    for(int i=0; i<n; i++){
        cin>> words[i];
    }
    
    for(int i=0; i<n; i++){
        curr= curr + words[i].size();
        if(curr>k){
            cout<< endl<< words[i];
            curr=words[i].size();
        } else {
            if(i==0){
                cout<< words[i];
            }else{
            cout<< " " << words[i];
            }
        }
    }


    return 0;
}