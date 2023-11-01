#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
  long long n,m,k;
  cin>> n >> m >> k;
  vector<long long> desired;
  vector<long long> sizes;

  long long ans=0;

  for(long long i=0; i<n; i++){
    long long a;
    cin>> a;
    desired.push_back(a);
  }

  for(long long i=0; i<m; i++){
    long long a;
    cin>> a;
    sizes.push_back(a);
  }
  sort(desired.begin(),desired.end());
  sort(sizes.begin(),sizes.end());
  long long curr=0;

  for(long long i=0; i<n; i++){
    for(long long j=curr; j<m; j++){
      if(abs(sizes[j]-desired[i])<=k){
        curr++;
        ans++;
        break;
      }

      if(sizes[j]>desired[i]){
        break;
      }else{
        curr++;
      }

    }
  }
  cout<< ans;
  return 0;
}
