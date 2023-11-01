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
  //ifstream cin("painti.txt");
  //ofstream cout("painto.txt");
  int t; cin>> t;
  while(t--){
    int w,o,b; cin >> w >> o >> b;
    int ow,bo,bw; cin>> ow >> bo >> bw;
    ow = min(ow,bo+bw);
    bo = min(bo, bw+ow);
    bw= min(bw, bo+ow);
    int convwhite = ow*o + bw*b;
    int convbrown = bo*o + bw*w;
    int convorange = ow*w + bo*b;
    int answer = min(convwhite,convbrown);
    answer= min(answer,convorange);
    cout<< answer << '\n';
  }

    return 0;
}
