//===============================================================================================
//                                                                ███████  ████████  ███████    |
//   ███████ ██   ██ ██████  ██ ██████  ██   ██  █████  ██████   ██     ██ ██    ██ ██     ██   |
//   ██      ██   ██ ██   ██ ██ ██   ██ ██   ██ ██   ██ ██   ██         ██     ██   ██     ██   |
//   ███████ ███████ ██████  ██ ██   ██ ███████ ███████ ██████    ███████     ██     ███████    |
//        ██ ██   ██ ██   ██ ██ ██   ██ ██   ██ ██   ██ ██   ██  ██          ██     ██     ██   |
//   ███████ ██   ██ ██   ██ ██ ██████  ██   ██ ██   ██ ██   ██  ██          ██     ██     ██   |
//                                                               █████████   ██      ███████    |
//===============================================================================================

// #95 : S.SHRIDHAR

#include <bits/stdc++.h>
using namespace std;
# define int long long

// ==============================================================================
// TYPE DEFINITIONS
// ==============================================================================

using uint = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

using vi = vector<int>;
using vc = vector<char>;
using vs = vector<string>;

using vpii = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvvi = vector<vvi>;
using mpii = map<int, int>;

template <typename T>
using maxheap = priority_queue<T>;

template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

// ==============================================================================
// MACROS & CONSTANTS
// ==============================================================================

#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define srt(x) sort(all(x))
#define rsrt(x) sort(rall(x))
#define rev(x) reverse(all(x))
#define lb lower_bound
#define ub upper_bound
#define uni(v) v.resize(unique(all(v)) - v.begin())
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, a, b) for (int i = a; i >=0; i--)
#define endl '\n'

#define precise(x) fixed << setprecision(x)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

const int mod7 = 1e9 + 7;
const int mod9 = 998244353;
const int MAXM = 2e5+5;
const int INF = 1e18;
const double EPS = 1e-9;

// --- Vector I/O ---
template <typename T>
istream &operator>>(istream &in, vector<T> &a)
{
    for (auto &x : a)
        in >> x;
    return in;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a)
{
    for (auto &x : a)
        out << x << ' ';
    return out;
}

// ==============================================================================
// DEBUGGING UTILITIES
// ==============================================================================

void _print(int a) { cout << a; }
void _print(pii a) { cout << a.ff << " " << a.ss; }
void _print(string a) { cout << a; }

template <class T>
void _print(vector<T> v)
{
    cout << "[ ";
    for (auto i : v)
    {
        _print(i);
        cout << " ";
    }
    cout << "]";
}

template <class T>
void _print(set<T> v)
{
    cout << "[ ";
    for (auto i : v)
    {
        _print(i);
        cout << " ";
    }
    cout << "]";
}

template <class T>
void _print(multiset<T> v)
{
    cout << "[ ";
    for (auto i : v)
    {
        _print(i);
        cout << " ";
    }
    cout << "]";
}

template <class T, class V>
void _print(map<T, V> v)
{
    cout << "[ ";
    for (auto [i, j] : v)
    {
        cout << "{ ";
        _print(i);
        cout << " ";
        _print(j);
        cout << " }";
    }
    cout << "]";
}

#define debug(x)             \
    do                       \
    {                        \
        if (check) {                       \
            cout << #x << " = "; \
            _print(x);           \
            cout << '\n';        \
        }                       \
    } while (0);

   
// ==============================================================================
// MATH & COMBINATORICS & NUMBER THEORY
// ==============================================================================

int binexp(int base, int exp, int m) // O(log exp)
{
    int res = 1;
    base %= m;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % m;
        base = (base * base) % m;
        exp /= 2;
    }
    return res;
}

int invmod(int n, int m) { return binexp(n, m - 2, m); } // O(log m) = O(1)

int fact[MAXM], invFact[MAXM];
void precomputeFactorials(int n = MAXM - 1, int m=mod7) // O(n) pp
{
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % m;
    invFact[n] = invmod(fact[n], m);
    for (int i = n - 1; i >= 1; i--)
        invFact[i] = (invFact[i + 1] * (i + 1)) % m;
}

int nCr(int n, int r, int m) // O(1) access after O(n) pp
{
    if (r < 0 || r > n)
        return 0;
    return ((1LL * fact[n] * invFact[r] % m) * invFact[n - r]) % m;
}

vector<int> primes;
bool is_prime[MAXM]; // O(n)
int spf[MAXM];       // O(n)

void sieve(int n = MAXM - 1) // O(n log log n)
{
    fill(is_prime, is_prime + n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 0; i <= n; i++)
        spf[i] = i;

    spf[0] = spf[1] = -1; // INVALID

    for (int p = 2; p * p <= n; p++)
    {
        if (is_prime[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                is_prime[i] = false;
                if (spf[i] == i)
                    spf[i] = p;
            }
        }
    }
    for (int p = 2; p <= n; p++)
        if (is_prime[p])
            primes.pb(p);
}

bool isprime(int x) { return is_prime[x]; }

// ==============================================================================
// FAST_IO
// ==============================================================================

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

#define check 0
// ==============================================================================
// SOLVE()
// ==============================================================================

void solve() {
    int n; cin >> n;
    vi a(n); loop(i, 0, n) cin >> a[i];
    vpii index;
    vi ans(n);
    loop(i, 0, n) {
        if (a[i]!=-1) {
            index.push_back({i, a[i]});
        }
    }
    int x = (int)index.size();
    ans=a;
    if (x==0) {
        loop(i, 0, n) {
            cout<<1;
        }
        cout<<endl;
        return;
    } else if (x==1) {
        for (int i=index[0].ff;i<n;i++) {
            ans[i]=max((int)0, index[0].ss-(i-index[0].ff));
        }
        for (int i=index[0].ff;i>=0;i--) {
            ans[i]=max((int)0, index[0].ss-(index[0].ff-i));
        }
        int flag=1;
        loop(i, 0, n) {
            if (ans[i]==0) {
                flag=0;
                break;
            }
        }
        if (flag) {
            cout<<-1<<endl;
        } else {
            loop(i, 0, n) {
                if (ans[i]==0)
                    cout<<1;
                else {
                    cout<<0;
                }
            }
            cout<<endl;
        }
        return;
    }
    vi direc;
    // 2 edge cases (front & back)
    if (index[0].ss<=index[0].ff) {
        direc.push_back(0);
        for (int i=index[0].ff-1;i>=0;i--) {
            ans[i]=max((int)0, index[0].ss+(i-index[0].ff));
        }
    } else {
        direc.push_back(1);
        for (int i=index[0].ff-1;i>=0;i--) {
            ans[i]=max((int)0, index[0].ss-(i-index[0].ff));
        }
    }
    // standard

    loop(i, 0, x-1) {
        int flg=1;
        if (index[i].ss+index[i+1].ss<=abs(index[i].ff-index[i+1].ff)) {
            loop(j, index[i].ff+1, index[i+1].ff) {
                ans[j]=max(index[i].ss+index[i].ff-j, (int)0);
            }
            for (int j=index[i+1].ff-1;j>index[i].ff;j--) {
                ans[j]=max({ans[j], index[i+1].ss+j-index[i+1].ff, (int)0});
            }
            loop(j, index[i].ff, index[i+1].ff+1) {
                if (ans[j]==0) {
                    flg=0;
                    break;
                }
            }
        }
        if (flg) {
            loop(j, index[i].ff+1, index[i+1].ff) {
                ans[j]=index[i].ss+j-index[i].ff;
            }
            for (int j=index[i+1].ff-1;j>index[i].ff;j--) {
                ans[j]=min(ans[j], index[i+1].ss+index[i+1].ff-j);
            }
            if (index[i+1].ss>index[i].ss) {
                direc.push_back(-1);
            } else if (index[i+1].ss<index[i].ss) {
                direc.push_back(1);
            } else {
                direc.push_back(2);
            }
        } else {
            direc.push_back(0);
        }
    }
    if (n-1-index[x-1].ss>=index[x-1].ff) {
        direc.push_back(0);
        for (int i=index[x-1].ff+1;i<n;i++) {
            ans[i]=max((int)0, index[x-1].ss-(i-index[x-1].ff));
        }
    } else {
        direc.push_back(-1);
        for (int i=index[x-1].ff+1;i<n;i++) {
            ans[i]=max((int)0, index[x-1].ss+(i-index[x-1].ff));
        }
    }
    int flag=1;
    loop(i, 0, n) {
        if (ans[i]==0) {
            flag=0;
            break;
        }
    }
    loop(i, 0, n-1) {
        if (abs(ans[i]-ans[i+1])>1) {
            flag=1;
            break;
        }
    }
    loop(i, 0, n-2) {
        if (ans[i]==ans[i+1] && ans[i+1]==ans[i+2] && ans[i]!=0) {
            flag=1;
            break;
        }
    }
    debug(ans)
    // debug(direc)
    // loop(i, 0, x) {
    //     if (direc[i]==1 && direc[i+1]==-1) {
    //         flag=1;
    //         break;
    //     }
    //     if (direc[i]==2 && direc[i+1]==-1) {
    //         flag=1;
    //         break;
    //     }
    //     if (direc[i]==1 && direc[i+1]==2) {
    //         flag=1;
    //         break;
    //     }
    //     if (direc[i]==2 && direc[i+1]==2) {
    //         flag=1;
    //         break;
    //     }
    // }
    int slope;
    if (ans[0]<ans[1] && ans[0]==0) {
        slope=-1;
    } else if (ans[0]>ans[1]) {
        slope=1;
    } else {
        if (ans[0]==0) {
            slope=1;
        } else {
            cout<<-1<<endl;
            return;
        }
    }
    loop(i, 2, n) {
        if (ans[i-1]>ans[i]) {
            if (slope==-1) {
                // its ok
            }
        } else if (ans[i-1]<ans[i]) {
            if (slope==1) {
                if (ans[i-1]==0) {
                    slope=-1;
                    continue;
                }
                cout<<-1<<endl;
                return;
            }
        } else {
            if (ans[i]==0) {
                slope=1;
                continue;
            }
            slope*=-1;
        }
        debug(slope)
    }
    if (slope==1 && ans[n-1]!=0) {
        cout<<-1<<endl;
        return;
    }
    if (flag==1) {
        cout<<-1<<endl;
        return;
    }
    loop(i, 0, n) {
        cout<<((ans[i]) ? 0 : 1);
    }
    cout<<endl;
}

int32_t main() {
    // precomputeFactorials();
    // sieve();
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
