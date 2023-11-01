#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265

long double SArea(int radius, long double angle){
    return (angle/360.0)*(PI)*(radius)*(radius);
}

long double TArea(int radius, long double angle){
    return (0.5)*(radius)*(radius)*(sin(angle*PI/180.0));
}

long double CArea(int radius){
    return PI*(radius)*(radius);
}

long double binsearch(long double da, int radius){
    long double l = 0.0, r = 90.0;
    long double ans;
        for(int i = 0; i < 1500; i++){
            long double m = l + (r-l)/2.0;
            long double area = SArea(radius, 2.0*m) - TArea(radius, 2.0*m);
            ans = m;
            if(area > da) r = m;
			else l = m;
        
        }
        return l;
}

int main(){
    //ifstream cin("input");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    int t; cin >> t;
    while(t--){
        set<long double> angles;
        int n,r; cin >> n >> r;
        if (n == 1){
            cout << setprecision(4) << fixed << 90.0000 << '\n';
            continue;
        }
        long double desiredarea = CArea(r)/(long double)(n+1);
        int done = 0;
        int num = 1;
        if(n%2==1) angles.insert(90.00);
        while(done < n){
            long double ans = binsearch((long double)num*desiredarea,r);
            angles.insert(ans);
            angles.insert(180.00000000 - ans);
            done += 2;
            num++;
        }
        for(auto u : angles){
            cout<< setprecision(4) << fixed << u << '\n';
        }
    }
    return 0;
}