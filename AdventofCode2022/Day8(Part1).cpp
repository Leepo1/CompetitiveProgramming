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


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ifstream cin("Day8(Part1)i.txt");
  ofstream cout("Day8(Part1)o.txt");
  string s;
  vector<string> v;
  int ans=0;
  while(cin>> s){
    v.push_back(s);
  }

  for(int i=0; i<v.size(); i++){
    for(int j=0; j<v[i].size(); j++){
      int height= v[i][j] - '0';

      //left
      int l=0;
      for(int g=j-1; g>=0; g--){
        int temp = v[i][g]-'0';
        if(temp>=height){
          l++;
          break;
        }
        l++;
      }


      //right
      int r=0;
      for(int g=j+1; g<v[i].size(); g++){
        int num = v[i][g]-'0';
        if(num>=height){
          r++;
          break;
        }
        r++;
      }

      //bot
      int b=0;
      for(int g=i-1; g>=0; g--){
        int num = v[g][j]-'0';
        if(num>=height){
          b++;
          break;
        }
        b++;
      }

      int u=0;
      for(int g=i+1; g<v.size(); g++){
        int num= v[g][j]-'0';
        if(num>=height){
          u++;
          break;
        }
        u++;
      }
      int temp = l*r*b*u;
      //cout<< temp;
      ans=max(temp,ans);
    }
  //  cout<< endl;
  }
  cout<< ans;
    return 0;
}
