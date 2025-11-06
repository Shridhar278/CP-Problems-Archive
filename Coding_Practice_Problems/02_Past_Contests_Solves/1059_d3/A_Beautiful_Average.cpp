#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF (int)1e9+7

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n, ele;
        vector<int> arr;
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> ele;
            arr.push_back(ele);
        }
        float max_avg = 0, sum = 0;
        for (int i=0;i<n;i++) {
            sum = 0;
            for (int j=i;j<n;j++) {
                sum += arr[j];
                if (sum > max_avg * (j - i + 1)) {
                    max_avg = (float)sum / (j - i + 1);
                }
            }
        }
        cout<<(int)max_avg<<endl;
    }
    return 0;
}