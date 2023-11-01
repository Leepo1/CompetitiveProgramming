#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main(){
 //ifstream cin("EvenMoreOddPhotosi.txt");
 //ofstream cout("EvenMoreOddPhotoso.txt");

  int n;
  cin>> n;
  int oddcount=0;
  int evencount=0;
  for(int i=0; i<n; i++){
    int a;
    cin>> a;
    if(a%2==0){
      evencount++;
    }else{
      oddcount++;
    }
  }

  if(oddcount>evencount){
    int t= oddcount-evencount;
    if(t%3!=0){
      oddcount-= 2*ceil((double)t/3);
      evencount+= ceil((double)t/3);
    }else{
      oddcount-= 2*(t/3);
      evencount+= (t/3);
    }
  }

  if(oddcount==evencount){
    cout<< 2*oddcount << '\n';
  }else{
    cout<< 2*oddcount+1 << '\n';
  }

  return 0;
}
