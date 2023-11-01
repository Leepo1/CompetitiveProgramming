#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <iomanip>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
vector<int> perm;
bool visited[5];

void p(int n, vector<int> perm, bool visited[n], int k){

  if(k==n){
    for(int i=0; i<n; i++){
      cout<< perm[i] << " ";
    }
    cout<< '\n';
    return;
  }

  for(int i=0; i<n; i++){
    if(visited[i]){
      continue;
    }

    perm.push_back(i);
    visited[i]=true;
    // subtask
    // Plugging the ways using one number
    p(n, perm, visited, k+1);
    // moving on to try the number of ways using the next number in this position
    visited[i]=false;
    perm.pop_back();
  }

  return;
}

int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  cout.tie(0);
  ifstream cin("i.txt");
  ofstream cout("o.txt");

  p(5, perm, visited, 0);

    return 0;
}
