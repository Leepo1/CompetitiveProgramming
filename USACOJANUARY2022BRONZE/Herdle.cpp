#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

map<char,int> ans;
map<char,int> gue;
int main(){
  for(char c='A'; c<='Z'; c++){
    ans[c]=0;
    gue[c]=0;
  }
  int greencount=0;
  int yellowcount=0;
  char answer[3][3];
  char guess[3][3];
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      cin>> answer[i][j];
      ans[answer[i][j]]++;
    }
  }
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      cin>> guess[i][j];
      gue[guess[i][j]]++;
    }
  }


  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      if(answer[i][j]==guess[i][j]){
        greencount++;
        ans[answer[i][j]]--;
        gue[guess[i][j]]--;
      }
    }
  }

  for(char c='A'; c<='Z'; c++){
    if(ans[c]>0 && gue[c]>0){
      yellowcount= yellowcount+ min(gue[c],ans[c]);
      ans[c]--;
      gue[c]--;
    }
  }
  cout<< greencount << endl;
  cout<< yellowcount;
    return 0;
}
