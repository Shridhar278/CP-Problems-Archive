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
    vi a(3); loop(i, 0, 3) cin >> a[i];
    sort(a.begin(), a.end());
    cout<<min(a[1], a[2]-a[0])<<endl;
}

int32_t main() {
    // precomputeFactorials();
    // sieve();
    fast_io();
    int test; 
    cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}
