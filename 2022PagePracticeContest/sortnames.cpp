#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;
struct person{
  string name;
  int age;
  int money;
};
bool comp(const person A, const person B){
  if(A.money==B.money){
    return A.age<B.age;
  }
  return A.money>B.money;
}
int main(){
  ifstream cin("sortnamesi.txt");
  int n;
  cin>>n;
  person arr[n];
  for(int i=0; i<n; i++){
    cin>> arr[i].name >> arr[i].age >> arr[i].money;
  }
  sort(arr,arr+n,comp);
  for(int i=0; i<n; i++){
    cout<< arr[i].name << " " <<  arr[i].age << " " << arr[i].money << '\n';
  }

  return 0;
}
