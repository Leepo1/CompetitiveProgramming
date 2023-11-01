#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <queue>
#include <stack>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;


int main(){
  ifstream cin("Day4-PassportProcessingi.txt");
  ofstream cout("Day4-PassportProcessingo.txt");

  int valid=0;
  string s;
  string arr[7] = {"byr", "iyr", "eyr", "hgt" , "hcl" , "ecl", "pid"};
  vector<string> v;

  while(getline(cin,s)){
    if(s.size()==0){

      map<string,bool> pass;

      for(int i=0; i<7; i++){
        pass[arr[i]]=false;
      }

      for(int i=0; i<v.size(); i++){

            string tag= v[i].substr(0,3);
            string result= v[i].substr(4,v[i].size()-4);
            //cout<< tag << " " << result << '\n';

            if(tag=="byr"){
              int birth = stoi(result);
              if(1920<=birth && birth<=2002){
                pass[tag]=true;
                continue;
              }else{
                break;
              }
            }

            if(tag=="iyr"){
              int issue= stoi(result);
              if(2010<=issue && issue<=2020){
                pass[tag]=true;
                continue;
              }else{
                break;
              }
            }

            if(tag=="eyr"){
              int exp= stoi(result);
              if(2020<=exp && exp<=2030){
                pass[tag]=true;
                continue;
              }else {
                break;
              }
            }

            if(tag=="hgt"){
              if(result.size()<=2){
                break;
              }
              string temp=result.substr(0,result.size()-2);
              bool check=true;
              for(int i=0; i<temp.size(); i++){
                if(!isdigit(temp[i])){
                  check=false;
                  break;
                }
              }
              if(!check) break;
              int height = stoi(temp);

              string unit= result.substr(result.size()-2,2);

              if(unit!="cm" && unit!="in") break;



              if(unit == "cm" && 150<=height && height<=193){
                pass[tag]=true;
                continue;
              }else if(unit == "in" && 59<=height && height<=76){
                pass[tag]=true;
                continue;
              }else {
                break;
              }
            }

            if(tag=="ecl"){
              if(result=="amb" || result=="blu" || result=="brn" || result=="gry" || result=="grn" || result=="hzl" || result== "oth"){
                pass[tag]=true;
                continue;
              }else{
                break;
              }
            }

            if(tag=="pid"){
              if(result.size()!=9){
                break;
              }
              bool check =true;
              for(int i=0; i<result.size(); i++){
                if(!isdigit(result[i])){
                  check=false;
                  break;
                }
              }

              if(!check) break;
              pass[tag]=true;
              continue;
            }

            if(tag=="hcl"){

              if(result[0]!='#'){
                break;
              }
              if(result.size()!=7){
                break;
              }
              bool check=true;
              for(int i=1; i<7; i++){
                if(isdigit(result[i]) || result[i]=='a' || result[i]=='b' || result[i]=='c' || result[i]=='d' || result[i]=='e' || result[i]=='f'){
                  continue;
                }else{
                    check=false;
                    break;
                }
              }
              if(check) pass[tag]=true;
          }

      }

      bool works=true;
      for(int i=0; i<7; i++){
        if(pass[arr[i]]==false){
          works=false;
          break;
        }
      }

      if(works) valid++;
      v.clear();

    }

    stringstream temp(s);
    string word;
    while(temp >> word){
      v.push_back(word);
    }

  }



  cout << valid << '\n';
    return 0;
}
