// DIRECTLY execute the GOD-DAMN thing right away : extra clever makes it tough
// READ carefully you JERK

// // PART 1

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define INF (int)(1e9+7)
// #define EPS (double)1e-9

// inline void fast_io() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
// }

// void solve() {
//     int n; cin >> n;
//     string str;
//     string total;
//     cin>>total;
//     for (int i=0;i<n-1;i++) {
//         cin >> str;
//         if (str < total) { // fails b < ba but still add ON end CASE bab < bba
//             str += total;
//             total = str;
//         } else {
//             total += str;
//         }
//     }
//     cout << total << endl;
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

// // PART 2

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define INF (int)(1e9+7)
// #define EPS (double)1e-9

// inline void fast_io() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
// }

// void solve() {
//     int n; cin >> n;
//     string str;
//     string total;
//     cin>>total;
//     for (int i=0;i<n-1;i++) {
//         cin >> str;
//         string x = str;
//         x += total;
//         if (x <= total) {
//             str += total;
//             total = str;
//         } else {
//             total += str;
//         }
//     }
//     cout << total << endl;
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