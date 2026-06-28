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

#define check 0
void solve() {
    int n; cin >> n;
    vi father(n+1);
    vi kids(n+1);
    loop(0, n-1) {
        cin >> father[i+2];
        kids[father[i+2]]++;
    }
    
    queue<int> q;
    loop(1, n+1) {
        if (kids[i]==0) {
            q.push(i);
        }
    }
    vi h1(n+1, 0);
    vi h2(n+1, 0);

    vi k=kids;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr==1) {
            continue;
        }

        if (h1[curr]+1>=h1[father[curr]]) {
            h2[father[curr]]=h1[father[curr]];
            h1[father[curr]]=h1[curr]+1;
        } else if (h1[curr]+1>=h2[father[curr]]) {
            h2[father[curr]]=h1[curr]+1;
        }

        debug(curr)
        debug(h1)
        debug(h2)

        k[father[curr]]--;
        
        if (k[father[curr]]==0) {
            q.push(father[curr]);
        }
    }

    loop(1, n+1) {
        if (kids[i]==0) {
            q.push(i);
        }
    }

    k=kids;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr==1) {
            continue;
        }

        h2[father[curr]]+=h2[curr];

        k[father[curr]]--;
        
        if (k[father[curr]]==0) {
            q.push(father[curr]);
        }
    }

    cout<<h2[1]+n<<endl;
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