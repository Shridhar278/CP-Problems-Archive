#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void encode(int n) {
    char str[10000]; int num;
    for (int i=0; i<n; i++) {
        cin>>num;
        str[i]=(char)(num+96);
    }
    cout<<str<<endl;
}

void decode() {
    char str[10001];
    cin>>str;
    int n=strlen(str);
    cout<<n<<endl;
    for (int i=0;i<n;i++) {
        cout<<str[i]-96<<" ";
    }
    cout<<endl;
}

int32_t main() {
    fast_io();
    char style[10];
    int n;
    cin>>style;
    if (style[0]=='f') {
        cin>>n;
        encode(n);
    } else {
        decode();
    }
    return 0;
}