#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
int n,m;
bool visited[1000];
vector<int> prefix;
int subsum;

bool check(vector<int> v, int chosen, vector<int> comb, int index){
    if(chosen==m-1){
        bool w=true;
        for(int i=0; i<m-1; i++){
            if(i==0){
                if(prefix[comb[i]]!=subsum){
                    w=false;
                }
            }else{
                if((prefix[comb[i]]-prefix[comb[i-1]])!=subsum){
                    w=false;
                }
            }
        }
        if(w) return true;
    }
    for(int i=index; i<n; i++){
        if(visited[i]) continue;
        visited[i]=true;
        comb.push_back(i);
        if(check(v,chosen+1,comb, i+1)) {return true;}
        visited[i]=false;
        comb.pop_back();
    }
    return false;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("PlayerDivisioni.txt");
  //ofstream cout("o.txt");

  int t; cin>> t;
  while(t--){
    for(int i=0; i<1000; i++){
        visited[i]=false;
    }
    cin>> n >> m;
    vector<int> v;
    int sum=0;
    for(int i=0; i<n; i++){
       v.push_back(i+1);
        sum+=i+1;
    }

    if(sum%m!=0){
        cout<< "Nah, maybe next year :(" << '\n';
        continue;
    }

    subsum= sum/m;
    bool works=false;

    do{
        prefix.clear();
        prefix.push_back(0);
        for(int i=0; i<n; i++){
            prefix.push_back(v[i]+prefix[i]);
        }
        vector<int> comb;
        if(check(v,0,comb,1)){
            works=true;
            break;
        }
    } while(next_permutation(v.begin(),v.end()));

    if(works){
        cout<< "SUIIIIIII!!!" << '\n';
    }else{
        cout<< "Nah, maybe next year :(" << '\n';
    }

  }
    return 0;
}
