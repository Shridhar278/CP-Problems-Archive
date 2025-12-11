#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// let's go '0' vacancies LOGIC
// DONE with ELEGANT minimalistic CODE

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n; cin >> n;
        char str[200001];
        cin >> str;
        vector <int> vacancies = {0};
        int curr=0;
        for (int i=0;i<strlen(str);i++) {
            if (str[i]=='1') {
                vacancies.back()+=curr;
                curr=0;
                vacancies.push_back(0);
            } else {
                curr++;
            }
        }
        vacancies.front()+=curr;
        // the highest COUNTS like if its like 1 2 4 6 7 => do +1 +1 +2 +2 +1 = 7
        cout<<*max_element(vacancies.begin(), vacancies.end())<<endl;
    }
    return 0;
}