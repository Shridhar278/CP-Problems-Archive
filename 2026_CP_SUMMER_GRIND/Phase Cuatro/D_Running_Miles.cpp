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
template<class T> void _print(multiset<T, greater<T>> v) {
    cout << "{ ";
    for (auto i : v) {
        _print(i);
        cout<<" ";
    }
    cout << "}";
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

// expecting TLE

// YES TLE less go


#define check 0
void solve() {
    int n; cin >> n;
    vi arr(n); loop(0, n) cin >> arr[i];
    
    multiset<int, greater<int>> curr; 
    for (int i=0;i<3;i++) {
        curr.insert(arr[i]);
    }

    int max_score=accumulate(curr.begin(), next(curr.begin(), 3), (int)0)-2;
    debug(max_score)
    int front=2, back=0;
    int strech=0, first=1;

    while(front!=back+2 or strech or first) {
        first=0;
        max_score=max(max_score, 
            accumulate(curr.begin(), next(curr.begin(), 3), (int)0)-(front-back));

        debug(max_score)
        debug(front)
        debug(back)
        debug(curr)

        //back tracking start

        //freebies
        while(front!=back+2) {
            auto it = find(curr.begin(), next(curr.begin(), 3), arr[back]);
            auto it2 = curr.find(arr[back]);

            debug(arr[back])
            debug(curr)
            if (it==next(curr.begin(), 3) or strech) {
                curr.erase(it2);
                back++;
            } else {
                break;
            }
            max_score=max(max_score, 
                accumulate(curr.begin(), next(curr.begin(), 3), (int)0)-(front-back));
        }

        if (strech) {
            break;
        }
        
        max_score=max(max_score, 
                accumulate(curr.begin(), next(curr.begin(), 3), (int)0)-(front-back));

        //look-back
        int b=back;
        multiset<int, greater<int>> now = curr;
        int curr_score = accumulate(now.begin(), next(now.begin(), 3), (int)0)-(front-b);

        while(front!=b+2) {
            auto it2 = now.find(arr[b]);

            debug(arr[b])
            debug(now)
            
            now.erase(it2);
            
            b++;
            if (accumulate(now.begin(), next(now.begin(), 3), (int)0)-(front-b) >= curr_score) {
                curr_score=accumulate(now.begin(), next(now.begin(), 3), (int)0)-(front-b);
                back=b;
                curr=now;
            }
        }

        max_score=max(max_score, 
            accumulate(curr.begin(), next(curr.begin(), 3), (int)0)-(front-back));

        //back tracking close

        debug(max_score)
        debug(front)
        debug(back)
        debug(curr)
        front++;

        if (front==n) { // last strech
            front=n-1;
            strech=1;
        } else {
            curr.insert(arr[front]);
        }
    }

    cout<<max_score<<endl;
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