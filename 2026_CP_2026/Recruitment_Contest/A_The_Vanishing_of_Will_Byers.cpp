#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        string str; cin >> str;
        int fals=0;
        for (int i=0;i<n;i++) {
            if (str[i]!=str[n-1-i]) {
                fals=1;
                if (k==0) {
                    cout<<1<<endl;
                    break;
                }
                cout<<2<<endl;
                break;
            } 
        }
        if (!fals) {
            cout<<1<<endl;
        }
    }
    return 0;
}
