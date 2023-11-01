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
typedef pair<long long,long long> ii;
typedef long long ll;
map<char, long long> m;
vector<long long> f;

long long decifromsnafu(string s){
  long long curr=0;
  reverse(s.begin(),s.end());
  for(long long i=0; i<s.size(); i++){
    curr+= f[i]*m[s[i]];
  }
  return curr;
}
string addsnafu(string a, string b){
  string answer="";
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  int carry=0;

  int asize=a.size();
  int bsize=b.size();
  if(a.size()>b.size()){
    for(int i=0; i<asize-bsize; i++){
      b+='0';
    }
  }else{
    for(int i=0; i<bsize-asize; i++){
      a+='0';
    }
  }

  int times = a.size();

  for(int i=0; i<times; i++){
    int amount = m[a[i]]+m[b[i]]+carry;
    cout<< amount<< " " << i << '\n';
    if(amount==-5){
      answer+= '0';
      carry=-1;
    }else if(amount==-4){
      answer+= '1';
      carry=-1;
    }else if(amount==-3){
      answer+= '2';
      carry=-1;
    }else if(amount==-2){
      answer+='=';
      carry=0;
    }else if(amount==-1){
      answer+='-';
      carry=0;
    }else if(amount==0){
      carry=0;
      if(i==times-1) break;
      answer+='0';
    }else if(amount==1){
      answer+= '1';
      carry=0;
    }else if(amount==2){
      answer+='2';
      carry=0;
    }else if(amount==3){
      answer+='=';
      carry=1;
    }else if(amount==4){
      answer+='-';
      carry=1;
    }else if(amount==5){
      answer+='0';
      carry=1;
    }
  }

  if(carry==-1) answer+='-';
  if(carry==1) answer+= '1';
  reverse(answer.begin(),answer.end());
  return answer;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("Day25i.txt");
//  ofstream cout("Day25o.txt");
  m['0']=0;
  m['1']=1;
  m['2']=2;
  m['-']=-1;
  m['=']=-2;
  string s;

  long long sum=0;
  long long product=1;
  f.push_back(1);
  for(long long i=1; i<50; i++){
    product*=5;
    f.push_back(product);
  }

  string f; cin>> f;
  sum+=decifromsnafu(f);
  int t=6;
  while(cin>> s){
    sum += decifromsnafu(s);
    f = addsnafu(f,s);
    cout<< decifromsnafu(f) << '\n';
    cout<< sum << '\n';
    cout<< f << '\n';
    cout<< s << " " << f << '\n';
  }

//  cout<< f << '\n';
//  cout<< sum << '\n';
//  cout<< decifromsnafu(f) << '\n';
    return 0;
}
