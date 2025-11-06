#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int test, n;
    cin >> test;
    int arr[999] = {0};
    vector<int>primes;
    for (int n=2;n<=32;n++) {
        int i = 2;
        if (arr[n-2]==0) {
            while (n*i <= 1000) {
                arr[n*i-2]=1;
                i++;
            }
        }
    }
    for (int a=0;a<999;a++) {
        if (arr[a]==0) {
            primes.push_back(a+2);
        }
    }
    // for (int x: primes) {
    //     cout<<x<<endl;
    // }
    while (test--) {
        cin >> n;
        int p = 0;
        int res = 1;
        int nw=1;
        vector<int> facts;
        while (n!=1) {
            if (p==primes.size()) {
                facts.push_back(2);
                break;
            }
            // cout<<n<<"a"<<primes[p]<<"a"<<facts.size()<<endl;
            if (n%primes[p]==0 && nw) {
                n/=primes[p];
                facts.push_back(2);
                nw=0;
            } else if (n%primes[p]==0 && !nw) {
                n/=primes[p];
                facts[facts.size()-1]++;
            } else {
                nw = 1;
                p++;
            }
        }
        for (int i=0;i<facts.size();i++) {
            res*=facts[i];
        }
        cout<<res<<endl;
    }
    return 0;
}