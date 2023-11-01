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
    int t;
    cin>> t;
    while(t--){
        int arr[3];
        cin>> arr[0] >> arr[1] >> arr[2];
        sort(arr,arr+3);
        if(arr[0]+arr[1]<=arr[2]){
            cout<< "No" << '\n';
        }else{
            cout<< "Yes" << '\n';
        }

    }
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/