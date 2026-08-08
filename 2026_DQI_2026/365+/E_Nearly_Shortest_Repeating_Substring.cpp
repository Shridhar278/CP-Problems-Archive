/*
                                                                ███████  ████████  ███████
   ███████ ██   ██ ██████  ██ ██████  ██   ██  █████  ██████   ██     ██ ██    ██ ██     ██
   ██      ██   ██ ██   ██ ██ ██   ██ ██   ██ ██   ██ ██   ██         ██     ██   ██     ██
   ███████ ███████ ██████  ██ ██   ██ ███████ ███████ ██████    ███████     ██     ███████
        ██ ██   ██ ██   ██ ██ ██   ██ ██   ██ ██   ██ ██   ██  ██          ██     ██     ██
   ███████ ██   ██ ██   ██ ██ ██████  ██   ██ ██   ██ ██   ██  ██          ██     ██     ██
                                                               █████████   ██      ███████
*/

// #95 : S.SHRIDHAR

#include <bits/stdc++.h>
using namespace std;
long long fastModularExp(long long base, long long exp, long long mod) {
  long long res = 1;
  base %= mod;
  while (exp > 0) {
    if (exp & 1) res = (res * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return res;
}
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

// got TLE #facs(max 128)*O(n)*c<- this was large
// so OPTIMIZED by not counting factors which are auto eliminated

// editorial logic -> main n/n-1 eles one of a[first] or a[last]
// so check for both if any one has <2 changes (0=ok, 1=one change) -> then found ! :)

#define check 1
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    set<int, greater<int>> facs;
    map<int, int> doit;
    for (int i=1;i*i<=n;i++) {
        if (n%i==0) {
            facs.insert(i);
            doit[i]=1;
            facs.insert(n/i);
            doit[n/i]=1;
        } 
    }
    int ans=n;
    for (auto ele : facs) {
        if (!doit[ele]) {
            continue;
        }
        vector<map<int, int>> digits(ele);
        int done=1;
        loop(0, n) {
            digits[i%(ele)][s[i]-'0']++;
        }
        int count=0;
        loop(0, ele) {
            int mini=INF;
            for (auto & [key, val] : digits[i]) {
                mini = min(mini, val);
            }
            if ((int)digits[i].size()>2) {
                done=0;
                break;
            } else if ((int)digits[i].size()==2 && mini>1) {
                done=0;
                break;
            } else if ((int)digits[i].size()==2 && mini==1) {
                count++;
            }
        }
        if (done && count<=1) {
            ans=ele;
        } else {
            for (int i=1;i*i<=ele;i++) {
                if (ele%i==0) {
                    doit[i]=0;
                    doit[ele/i]=0;
                } 
            }
        }
    }
    cout<<ans<<endl;
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