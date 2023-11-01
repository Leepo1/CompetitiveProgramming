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
const int Z= 2e5 +5;
vector<int> children[Z];
int subtree[Z];

void dfs(int node){
    subtree[node]=1;
    for(int child : children[node]){
        dfs(child);
        subtree[node]+= subtree[child];
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>> n;

    for(int i=2; i<=n; i++){
        int c; cin >> c;
        children[c].push_back(i);
    }

    dfs(1);
    for(int i=1; i<=n; i++){
        cout<< subtree[i]-1 << " ";
    }
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/
