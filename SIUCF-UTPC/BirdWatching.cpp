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
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;

long long arr[100005];
int main(){


  //ifstream cin("BirdWatchingi.txt");
  //ofstream cout("BirdWatchingo.txt");
  int n,m;
  cin>> n >> m;
  /*
  for(int i=0; i<100005; i++){
    arr[i]=0;
  }
  for(int i=0; i<n; i++){
    int a,b;
    cin>> a >> b;
    arr[a]++;
    arr[b+1]--;
  }
 
  for(int i=1; i<100005; i++){
    arr[i]=arr[i]+arr[i-1];
  }
  for(int i=1; i<100005; i++){
    arr[i]=arr[i]+arr[i-1];
  }

  for(int i=0; i<m; i++){
    int a,b;
    cin>> a >> b;
    cout<< arr[b]-arr[a-1] << '\n';
  }
  */
  cout<< n << " " << m << '\n';
    return 0;
}
