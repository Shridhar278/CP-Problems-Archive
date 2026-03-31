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

// missing A case
// WILL DO POST-martum TIRED AS HELL so far

// mysterIO

// will REMAIN as a SCAR

#define check 1
void solve() {
    int n, k; cin >> n >> k;
    vi arr(n); loop(0, n) cin >> arr[i];
    vi vary(n); loop(0, n) cin >> vary[i];
    map exists;
    map wants;
    vi appends; int counter=0;
    loop(0, k) {
        wants[arr[i]]++;
        if (vary[i]>0) {
            exists[vary[i]]++;
        } else {
            appends.push_back(i);
        }
    }
    loop(0, k) {
        if (i+k<n) {
            if (vary[i+k]>0 and arr[i+k]!=vary[i+k] and arr[i]==arr[i+k]) {
                if (vary[i]<0) {
                    vary[i]=vary[i+k];
                    appends.erase(find(appends.begin(), appends.end(), i));
                    exists[vary[i+k]]++;
                    continue;
                }
            }
        }
        if (vary[i]<0 and exists[arr[i]]<wants[arr[i]]) {
            vary[i]=arr[i];
            exists[vary[i]]++;
            appends.erase(find(appends.begin(), appends.end(), i));
        } 
    }
    loop(0, k) {
        if (exists[arr[i]]<wants[arr[i]]) {
            if (counter<(int)appends.size() and appends[counter]<k) {
                vary[appends[counter]]=arr[i];
                counter++;
                exists[arr[i]]++;
            } else {
                cout<<"NO"<<endl;
                return;
            }
        } else if (exists[arr[i]]>wants[arr[i]]) {
            cout<<"NO"<<endl;
            return;
        }
    }
    loop(0, n-k) {
        if (arr[i]==vary[i]) {
            exists[arr[i]]--;
            if (vary[i+k]>0) {
                if (arr[i+k]==vary[i+k]) {
                    exists[arr[i+k]]++;
                } else {
                    cout<<"NO"<<endl;
                    return;
                }
            } else {
                exists[arr[i+k]]++;
                vary[i+k]=arr[i+k];
            }
        } else {
            if (vary[i+k]>0) {
                if (arr[i]==arr[i+k] and vary[i]==vary[i+k]) {
                    // it is what it is
                } else {
                    cout<<"NO"<<endl;
                    return;
                }
            } else {
                if (arr[i+k]!=arr[i]) {
                    cout<<"NO"<<endl;
                    return;
                } else {
                    vary[i+k]=vary[i];
                }
            }
        }
    }
    cout<<"YES"<<endl;
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