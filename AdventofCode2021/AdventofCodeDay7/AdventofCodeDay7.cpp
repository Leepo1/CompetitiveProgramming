#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
using namespace std;

int main(){
  //105192742
  ifstream cin("AdventofCodeDay7.in");
  ofstream cout("AdventofCodeDay7.out");
  vector<int> v;
  int x;
  char c;
  while (cin>>x) {
 v.push_back(x);
 cin>>c;
  }
  long long minimum=10000000000000;

  int vsize=v.size();

  long long answer=0;
  long long sum=0;
  sort(v.begin(),v.end());
  /*
for(int i=0; i<vsize; i++){
  sum=sum+v[i];
}
*/
for(int i=0; i<=v[999]; i++){
  long long mean=i;
  answer=0;
   for(int j=0; j<vsize; j++){
  long long first= abs(v[j]-mean);
  answer= answer+((first)*(first+1))/2;

  }

minimum= min(answer, minimum);
}
cout<< minimum;
//mean= round(((float)sum)/((float)vsize));



    return 0;
}
