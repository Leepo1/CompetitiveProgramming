#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

vector<int> v;

int main(){

  ifstream cin("I-MaximumProduct.txt");
  ofstream cout("O-MaximumProduct.txt");

  int rp;// Product you want to reach

  int n;// Number of elements in array
  cin>> n;
  int arr[n]; // Numbers

  long long possible=0;
  for(int i=0; i<n; i++){
  cin>> arr[i];
  possible+=arr[i];
  }
  cin>> rp;
  sort(arr,arr+n);
  reverse(arr,arr+n);

  bitset<15> b= {0}; // Use bitset to iterate through each possible subset

  int temp=b.to_ullong();

  string now= b.to_string();

  for(int i=1; i<=(1<<10); i++){
    // Clears old subset
    v.clear();

    //product and sum
    long long pp=1;
    long long tsum=0;

    now=b.to_string();

    int count=0;
    int actual=0;
    //Puts number into vector if its a 1
    for(auto a: now){

      if(a=='1'){
        v.push_back(arr[count]);
        pp*=arr[count];
        tsum+=arr[count];
      }
        if(actual>=(15-n)){
            count++;
        }
        actual++;


    }

    // If it works on that subset
    if(pp>=rp){
      possible= min(possible,tsum);
    }
    temp++;
    b=temp;
  }
  cout<< possible;
return 0;
}
