#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;


int main(){


  //ifstream cin("GroceryShoppingi.txt");
  //ofstream cout("GroceryShoppingo.txt");

  string s;
  cin>> s;
  int a= stoi(s.substr(0,1));
  int l= s.size()-1;
  string answer="";
  int current = 1;
  while(true){
    if (a=='1'||a=='3'||a=='5'||a=='9'){
      answer+=a;
      l--;
      a = stoi(s.substr(current,1));
      current++;

    }else{
      if (a<1){
        answer+='1'
      }else if (a<3){
        answer+='3'
      }else if(ans<5){
        answer+='5'
      }else {
        answer+='9';
      }
      for(int i=0; i<l; i++){
        ans+='1';
      }
      current=s.size()+5;
    }

    if(current>s.size+1)
  }


  if(a==7){
    answer+='7';
  }else if(a==1){
    answer+='1';
  }else if(a==3){
    answer+='3';
  }else if(a==5){
    answer+='7';
  } else if(a==9){
    answer+='9';
  }else if (a==0){
    string temp= to_string(a+1);
    answer+=temp;
  }
  for(int i=0; i<l-1; i++){
    answer+='1';
  }
  cout << answer;

return 0;
}
