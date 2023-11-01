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

int N=200000;
vector<int> adj[N];
bool visited[N];
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("BarnTreei.txt");
  ofstream cout("BarnTreeo.txt");
  int n; cin>> n;
  int bales[n];
  int sum=0;

  for(int i=0; i<n; i++){
    cin>> bales[i];
    sum+=bales[i];
  }

  int amount= sum/n;

  for(int i=0; i<n-1; i++){
    int a,b; cin>> a >> b;
    a--; adj[a].push_back(b);
    b--; adj[b].push_back(a);
  }


    return 0;
}
