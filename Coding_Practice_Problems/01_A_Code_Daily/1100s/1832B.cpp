#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int test;
    cin>>test;
    while(test--) {
        ll n, k, sum=0;
        cin>>n>>k;
        vector<ll> a(n);
        for (int i=0;i<n;i++) {
            cin>>a[i];
            sum+=a[i];
        }
        sort(a.begin(), a.end());
        ll mini=0, j=k;
        for (int i=0;i<2*j;i++) {
            mini += a[i];
        }
        ll curr = mini;
        while (j) {
            curr = curr - a[2*j-1]-a[2*j-2]+a[a.size()-k+j-1];
            if (curr < mini) {
                mini = curr;
            }
            j--;
        }
        cout<<sum-mini<<endl;
    }
    return 0;
}