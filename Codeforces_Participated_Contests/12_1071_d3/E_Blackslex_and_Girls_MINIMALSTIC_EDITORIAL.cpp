// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define INF (int)(1e9+7)
// #define EPS (double)1e-9

// inline void fast_io() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
// }

// // a lot of EXTRATERRESTIAL thinking i did i guess
// // but taking CORRECT CASES *understanding* was PHENOMINAL

// // OVERCOMPLICATED in MINE

// LETs DO THIS
// void solve() {
    
// }

// int32_t main() {
//     fast_io();
//     int test;
//     cin >> test;
//     while (test--) {
//         solve();
//     }
//     return 0;
// }

//issues over this

/* Case 2: if all districts have the same designated winner, sometimes there are too many votes from the 'losing' party for a solution to exist. The minimum votes the winning party must have over the losing party is n
, because we need a strict majority in every district, which corresponds to a vote difference of at least 1 in each district. WLOG let x
 be the votes from the winning party and y
 be the votes from the losing party, and we simply check if x>=y+n. */



#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
void test_case_run() {
    int n;
    ll x, y;
    cin >> n >> x >> y;
    
    string s;
    cin >> s;
    s = '.'+s;
    
    ll p[n+1];
    for (int i = 1; i <= n; i++) cin >> p[i];
    
    if (accumulate(p+1, p+n+1, 0LL) > x+y) {
        cout << "NO\n";
        return;
    }
    
    if (s == "." + string(n, '0') || s == "." + string(n, '1')) {
        if (s == "." + string(n, '1')) {
            swap(x, y);
        }
        
        ll x_need = 0;
        for (int i = 1; i <= n; i++) {
            x_need += p[i]/2 + 1;
        }
        
        if (x < x_need || x < y+n) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
        
        return;
    }
    
    ll x_need = 0, y_need = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            x_need += p[i]/2 + 1;
        } else {
            y_need += p[i]/2 + 1;
        }
    }
    if (x >= x_need && y >= y_need) cout << "YES\n";
    else cout << "NO\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) test_case_run();
    
    return 0;
}