#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

int main(){
  //ifstream cin("coffeei.txt");
  //ofstream cout("coffeeo.txt");
  int t;
  cin>> t;
  while(t--){
    int a,b;
    cin>> a >> b;
    int answer= (a*b)/60;
    cout<< answer<< endl;
  }

  return 0;
}
