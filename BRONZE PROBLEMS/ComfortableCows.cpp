#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
bool grid[1000][1000];

bool comfortable(pii c){
    int count=0; 
    if(grid[c.first-1][c.second]==true){
        count=count +1;
    } if(grid[c.first][c.second-1]==true){
            count=count+1;
        } if(grid[c.first+1][c.second]==true){
            count=count+1;
        } if(grid[c.first][c.second+1]==true){
            count=count+1;
        }
        if(count==3){
            return true;
        }else {
            return false;
        }
    }
    
vector<pii> v;
int main(){
 int n;
 cin>> n;
int x, y;
for(int i=0; i<1001; i++){
    for(int j=0; j<1001; j++){
        grid[i][j]=false;
    }
}
    for(int i=0; i<n; i++){
        cin>> x>>y;
        grid[x][y]=true;
        v.push_back(make_pair(x,y));
        int comcount=0;
        for(int j=0; j<i+1; j++){
            comcount=0;
            if(comfortable(v[j])){
                comcount=comcount+1;
            }
        }
        cout<< comcount<< endl;
    }
    
    

    return 0;
}