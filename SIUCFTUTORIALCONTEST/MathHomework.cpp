#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <iomanip>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;


int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  cout.tie(0);
  ifstream cin("MathHomeworki.txt");
  ofstream cout("MathHomeworko.txt");
  int f,s,t,total;
  cin>> f >> s >> t >>total;
  for(int i=0; i<total/f; i++){
    for(int j=0; j<total/s; j++){
      for(int g=0; g<total/g; g++){
        if(f*i + j+s + g*t==total){
          cout<< i << " " << j << " " g << endl;
        }
      }
    }
  }
    return 0;
}
