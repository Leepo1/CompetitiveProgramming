#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int n;
int arr[15];

bool visited[15];
int ans=0;
int up, down;
void recurse(vector<int> p,  int k){

  if(k==n){
    ans++;
    return;
  }

  for(int i=0; i<n; i++){
    if(visited[i]){
      continue;
    }
    if(p.size()!=0){
      if(arr[p[k-1]]+up<arr[i]){
        continue;
      }else if(arr[p[k-1]]-down>arr[i]){
        continue;
      }
    }
    p.push_back(i);
    visited[i]=true;
    recurse(p,k+1);
    p.pop_back();
    visited[i]=false;
  }

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ifstream cin("jumpinggamei.txt");
  ofstream cout("jumpinggameo.txt");
  int c;
  cin >> c;
  while(c--){
    ans=0;
    vector<int> p;
    cin>> n;
    for(int i=0; i<n; i++){
      cin>> arr[i];
      visited[i]=false;
    }
    cin>> up >> down;

    recurse(p, 0);
    cout<< ans << '\n';
  }
    return 0;
}
