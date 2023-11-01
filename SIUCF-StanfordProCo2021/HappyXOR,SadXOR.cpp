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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    ll arr[n];
    ll sum = 0;
   for(int i=0; i<n; i++){
        cin>> arr[i];
        sum+=arr[i];
   }

    ll y;

    int cur = arr[0];
    for(int i=1; i<n; i++){
        cur^=arr[i];
    }
    y=cur;
    cout<< abs(sum-y);
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/