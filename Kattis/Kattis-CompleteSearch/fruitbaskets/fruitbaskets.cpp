#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <set>
#include <map>
#include <vector>

using namespace std;


int main(){

  ifstream cin("fruitbasketsi.txt");
  ofstream cout("fruitbasketso.txt");

  int n;
  cin>> n;
  int fruits[40];
  for(int i=0; i<n; i++){
    cin>> fruits[i];
  }

  return 0;
}
