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
map<int,int> position;
map<int,int> faggot;
vector<int> numbers;
int m;
//4526232706281
int mod(int a, int base){
  while(a<0){
    a+=base;
  }
  return a%base;
}

void transfrom(int i){
  int eq = mod(numbers[i],m);
  if(numbers[i]<0){
    eq-=m;
  }
  if(eq==0) return;
  int fp = position[i]+eq;
  if(fp<=0){
    fp = (m-1)+fp;
  }else if(fp>(m-1)){
    fp = fp-(m-1);
  }
  int op = position[i];
  if(op==fp) return;
  position[i]=fp;
  for(int e=0; e<m; e++){
    if(e==i) continue;
    if(position[e]<op && position[e]>=fp){
      position[e]++;
    }else if(position[e]>op && position[e]<=fp){
      position[e]--;
    }
  }
}


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("Day20i.txt");
  //ofstream cout("Day20o.txt");
  int x;
  int p=0;
  while(cin >> x){
    numbers.push_back(x);
    position[p]=p;
    p++;
  }
  m=numbers.size();
  for(int i=0; i<m; i++){
    transfrom(i);
  }
  int zero=0;
  for(int i=0; i<m; i++){
    faggot[position[i]]=numbers[i];
    if(numbers[i]==0) zero=position[i];
  }

  int f =  (zero+1000);
  int s = (zero+2000);
  int t = (zero+3000);
  if(f>(m-1)){
    f=f-(m-1)-1;
  }
  if(s>(m-1)){
    s=s-(m-1)-1;
  }
  if(t>(m-1)){
    t=t-(m-1)-1;
  }
  cout<< f << s << t << '\n';
  int sum = faggot[f]+faggot[s]+faggot[t];
  cout<< sum;
    return 0;
}
