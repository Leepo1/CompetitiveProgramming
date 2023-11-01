#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

int main(){
//  ifstream cin("nexti.txt");
//  ofstream cout("nexto.txt");
  int t;
  cin>> t;
  while(t--){
    char a,b,c;
    string s;
    cin>> s;
    a=s[0];
    b=s[1];
    c=s[2];


    if(c=='Z'){
      c='A';
      if(b=='Z'){
        b='A';
        if(a=='Z'){
          cout<< "AAA" << '\n';
          continue;
        }else{
          a++;
        }
      }else{
        b++;
      }
    }else{
      c++;
    }

    string se="";
    se+=a;
    se+=b;
    se+=c;
    cout<< se << '\n';

  }
  return 0;
}
