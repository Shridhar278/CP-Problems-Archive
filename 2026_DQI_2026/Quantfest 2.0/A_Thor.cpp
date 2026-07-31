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

#define check 0
void solve() {
    int n, q; cin >> n >> q;
    int x, y;
    vvi init(n+1);
    int total=0;
    vi events(q+1, -1);
    vi father(q+1, -1);
    set<int> unread;
    for (int j=0, i=1;j<q;j++) {
        cin >> x >> y;
        switch (x) {
            case 1:
                if (init[y].empty()) {
                    init[y]=vi({i, i, 1});
                } else {
                    events[init[y][1]]=i;
                    init[y][1]=i;
                    init[y][2]++;
                }
                unread.insert(i);
                father[i]=y;
                total++;    
                i++;    
                break;
            case 2:
                if (!init[y].empty()) {
                    total-=init[y][2];
                    while (init[y][0]!=-1) {
                        int temp = init[y][0];
                        init[y][0] = events[init[y][0]];
                        unread.erase(temp);
                    }
                    vi temp; temp.swap(init[y]); 
                }
                break;
            case 3:
                // reduce complexity here
                auto it=unread.begin();
                for (;it!=unread.end();) {
                    int ele = *it;
                    if (ele>y) {
                        break;
                    } else {
                        init[father[ele]][0]=events[init[father[ele]][0]];
                        total--;
                        init[father[ele]][2]--;
                        if (init[father[ele]][0]==-1) {
                            vi temp; temp.swap(init[father[ele]]); 
                        }
                        it++;
                    }
                }
                unread.erase(unread.begin(), it);
        }
        cout<<total<<"\n";
        debug(init)
    }
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}