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
            cout<<#x<<" = "; _print(x); cout<<endl \
        } \
    } while(0)

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
    string s; cin >> s;
    vi alphas(26);
    loop(0, s.size()) {
        alphas[s[i]-'A']++;
    }
    int odd=0, index;
    loop(0, 26) {
        if (alphas[i]%2) {
            odd++;
            index=i;
            if (odd==2) {
                cout<<"NO SOLUTION"<<endl;
                return;
            }
        } else {
            alphas[i]/=2;
        }
    }
    int i=0, j=0, forward=1;
    while(i<s.size()) {
        if (odd==1) {
            if (j==index) {
            if (forward) {
                j++;
            } else {
                j--;
            }
            continue;
        }
        }
        loop(0, alphas[j]) {
            cout<<char('A'+j);
        }
        i+=alphas[j];
        if (forward) {
            j++;
        }
        if (j==26) {
            forward=0;
            if (odd==1) {
                loop(0, alphas[index]) {
                cout<<char('A'+index);
            }
            i+=alphas[index];
            }
        }
        if (!forward) {
            j--;
        }
    }
    cout<<endl;
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}