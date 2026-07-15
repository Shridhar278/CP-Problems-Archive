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
    string a,b;
    cin>>a>>b;
    int n=a.size(),m=b.size();
    vector<int> A(26,-1),B(26,-1);
    for(int i=1;i<n;i++) A[a[i]-'a']=i;
    for(int i=0;i<m-1;i++) B[b[i]-'a'] = i;
    
    int len=1e9;
    string ans;
    int indx1=-1;
    int indx2=-1;
    for(int i=1;i<n;i++)
    {
        if(B[a[i]-'a']==-1) continue;
        int curr = i+1 + (m-B[a[i]-'a']);
        if(curr < len)
        {
            len = curr;
            indx1=i;
            indx2 = B[a[i]-'a'];
        }
    }
    if(len==1e9)
    {
        cout<<-1<<'\n';
        return;
    }
    //cout<<indx1<<' '<<indx2<<'\n';
    for(int i=0;i<=indx1;i++) ans.push_back(a[i]);
    for(int i=indx2+1;i<m;i++) ans.push_back(b[i]);
    cout<<ans<<'\n';
}

int32_t main() {
    fast_io();
    solve();
    return 0;
}