/////////////////////////////////////////////////////////////////////////////
// @@@@@  @   @  @@@@  @@@@@ @@@@   @   @   @@@   @@@@   @@@@@ @@@@@ @@@@@ //
// @      @   @  @   @   @   @   @  @   @  @   @  @   @      @    @  @   @ //
// @@@@@  @@@@@  @@@@    @   @   @  @@@@@  @@@@@  @@@@   @@@@@   @    @@@  //
//     @  @   @  @  @    @   @   @  @   @  @   @  @  @   @       @   @   @ //
// @@@@@  @   @  @   @ @@@@@ @@@@   @   @  @   @  @   @  @@@@@   @   @@@@@ //
/////////////////////////////////////////////////////////////////////////////
//smudge your eyes a little to see the trademark

#include <bits/stdc++.h>
using namespace std;
#define int  long long

void _print(int a) {
   cout << a;
}
void _print(string a) {
   cout << a;
}
void _print(char a) {
   cout << a;
}
template<class T> void _print(vector<T> v) {
    cout << "[ ";
    for (auto i : v) {
        _print(i);
        cout << " ";
    }
    cout << "]";
}
template<class T> void _print(map<T, T> v) {
    cout << "[ ";
    for (auto [i, j] : v) {
        cout << "{ ";
        _print(i);
        cout << " ";
        _print(j);
        cout << " }";
    }
    cout << "]";
}

#define debug(x) \
   do { \
        if (check) {\
            cout<<#x<<" = "; _print(x); cout<<endl; \
        } \
    } while(0);

#define loop(k, n) for(int i=k;i<n;i++)
#define precise(x) cout << fixed << setprecision(x)
#define vi vector<int>
#define vvi vector<vector<int>>
#define map map<int, int>
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define el cout<<endl;

const int mod7 = 1e9 + 7;
const int mod9 = 998244353;
const int INF = 1e18;
const double EPS = 1e-9;

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

#define check 1
void solve() {
    int n; cin >> n;
    vi arr(n); loop(0, n) cin >> arr[i];
    vi distinct;
    for (int i=0;i<n;) {
        vvi isthere(n+1, vi(2));
        isthere[arr[i]][0]=1;
        isthere[arr[i]][1]=i;
        int j;
        for (j=i+1;j<n;j++) {
            if (isthere[arr[j]][0]) {
                break;
            } else {
                isthere[arr[j]][0]++;
                isthere[arr[j]][1]=j;
            }
        }
        debug(j);
        debug(isthere)
        for (int k=n;k>0;) {
            if (!isthere[k][0]) {
                k--;
                continue;
            }
            vi new_arr;
            int l;
            for (l=k;l>0;l--) {
                if (!isthere[l][0]) {
                    break;
                }
                new_arr.push_back(isthere[l][1]);
            }
            int x = *max_element(new_arr.begin(), new_arr.end())-
            *min_element(new_arr.begin(), new_arr.end());
            if (x+1==(int)new_arr.size()) {
                distinct.push_back(x+1);
            }
            debug(new_arr);
            debug(distinct);
            k=l-x;
        }
        i=j;
        debug(distinct)
        debug(i)
    }
    int h1=-1;
    int h2=-1;
    debug(distinct)
    for (int i=0;i<(int)distinct.size();i++) {
        if (distinct[i]>=h1) {
            h2=h1;
            h1=distinct[i];
        } else if (distinct[i]>=h2) {
            h2=distinct[i];
        }
    }

    // cout<<max(h2, (int)1)<<endl;
    
    auto it = max_element(distinct.begin(), distinct.end());
    int i=0;
    for (auto x=distinct.begin();x!=distinct.end();x++) {
        i+=*x;
    }
    // target is now x to x+h1-1
    // find 2 disjoint EQUAL SMALLER
    for (int i=max((int)1, h2);i<=h1/2;i++) {
        
    }
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}