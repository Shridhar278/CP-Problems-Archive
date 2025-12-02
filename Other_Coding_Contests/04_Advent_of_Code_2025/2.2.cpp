#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int digits(int n) {
    if (n >= 100000000000) return 12;
    if (n >= 10000000000)  return 11;
    if (n >= 1000000000)   return 10;
    if (n >= 100000000)    return 9;
    if (n >= 10000000)     return 8;
    if (n >= 1000000)      return 7;
    if (n >= 100000)       return 6;
    if (n >= 10000)        return 5;
    if (n >= 1000)         return 4;
    if (n >= 100)          return 3;
    if (n >= 10)           return 2;
    return 1;
}

int32_t main() {
    fast_io();
    int count=0;
    while(true) {
        int n1, n2; char c;
        cin >> n1;
        if (n1==0){
            break;
        }
        cin>>c; /*'-' sign*/ cin >> n2; /*',' sign*/ cin>>c;
        
    }
    cout<<count<<endl;
    return 0;
}