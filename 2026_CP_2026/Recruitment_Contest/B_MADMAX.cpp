#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while(t--) {
        int n, a, b; cin >> n >> a >> b;
        string str; cin >> str;
        int n0=0, n1=0;
        for (int i=0;i<n;i++) {
            if (str[i]=='0') {
                n0++;
            } else {
                n1++;
            }
        }
        if (n1==0 or n0==0) {
            cout<<0<<endl;
            continue;
        }
        int as=0, bs=0;
        int min_so_far=100000000;
        for (bs=0;2*bs<=n1;bs++) {
            as=n1-2*bs;
            min_so_far = min(min_so_far, as*a+bs*b);
        }
        min_so_far = min(min_so_far, min(a, b)*n0);
        cout<<min_so_far<<endl;
    }
    return 0;
}
