#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <iomanip>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int,int> pi;
typedef long long ll;
typedef pair<int,pair<int,int>> pii;

map<char,int> day;


int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  cout.tie(0);
  //ifstream cin("piloti.txt");
  //ofstream cout("piloto.txt");
  int c;
  cin>> c;
  day['M']=0;
  day['T']=1;
  day['W']=2;
  day['R']=3;
  day['F']=4;
  day['S']=5;
  day['U']=6;
  while(c--){
    int n, m;
    cin>> n  >> m;
    int s[n];
    int e[n];
    bool flag=false;
    for(int i=0; i<n; i++){
      char c;
      cin >>c;
      int start,length;
      cin>> start >> length;
      s[i]= start + day[c]*24;
      e[i]= s[i]+ length;
    }


    sort(s,s+n);
    sort(e,e+n);

    int currstart=s[0];
    int currend= e[0];
    for(int i=1; i<n; i++){
      if(s[i]==currend){
        currend= e[i];
        if(currend-currstart>m){
          flag=true;
        }
      }else{
        currstart=s[i];
        currend=e[i];
      }
    }
    if(currend-currstart>m){
      flag=true;
    }
    if(flag){
      cout<< "Take a rest." << '\n';
    }else{
      cout<< "Good to go!" << '\n';
    }
  }



    return 0;
}
