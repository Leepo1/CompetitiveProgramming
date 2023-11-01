#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <iterator>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int Z=2e5+5;
bool visited[Z];
int main() {

    ifstream cin("TreeMatchingi.txt");
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>> n;
    queue<ii> q;
    int answer=0;
    for(int i=1; i<n; i++){
        ii temp;
        cin>> temp.first >> temp.second;
        q.push(temp);
    }
    
    while(!q.empty()){
        ii temp= q.front();
        q.pop(); 
        if(visited[temp.first] || visited[temp.second]){
            continue;
        }
        else{
            visited[temp.first]=true;
            visited[temp.second]=true;
            answer++;
        }
    }
    cout<< answer << '\n';
    long long mugiwara = 99999999999;
    for(long long i=0;i<mugiwara; i++){
        cout<<"Mugiwara";
    }
    return 0;
}
/*
 stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/