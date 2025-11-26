#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int fact(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++)
        res *= i;
    return res;
}

// lesson learnt: we can use next_permuatation() function to reduce brute force

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    char str[5];
    int all[3][24] = {  {12, 21},
                        {123, 132, 213, 231, 312, 321},
                        {1234, 1243, 1324, 1342, 1423, 1432,
                         2134, 2143, 2314, 2341, 2413, 2431,
                         3124, 3142, 3214, 3241, 3412, 3421,
                         4123, 4132, 4213, 4231, 4312, 4321}   }; 
    while (test--) {
        cin>>str;
        int n = strlen(str);
        int same=0;
        int i, j; cin >> i >> j; i--; j--;
        i = all[n-2][i];
        j = all[n-2][j];
        for (int k = n; k > 0; k--) {
            if (i/(int)pow(10, k-1) == j/(int)pow(10, k-1)) same++;
            i %= (int)pow(10, k-1);
            j %= (int)pow(10, k-1);
        }
        cout<<same<<"A"<<n - same<<"B\n";
    }
    return 0;
}