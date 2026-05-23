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
#define int  int

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

#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int mod=1e9+7;
 
int modpower(int a, int b)
{
    int r=1;
    
    a=a%mod;
    while(b>0)
    {
        if(b%2==1)
        {
            r*=a;
            r%=mod;
        }
        
        b=b/2;
        a*=a;
        a%=mod;
        
    }
    
    return r;
}
 
 
int32_t main(){
    int t;
    cin>>t;
 
    while(t--){
        int a, b, k;
        cin>>a>>b>>k;
        
        int n=1, m=1;
        
        n*=a-1;
        n%=mod;
        n*=k;
        n%=mod;
        n+=1;
        n%=mod;
        
        m*=b-1;
        m%=mod;
        m*=k;
        m%=mod;
        for(int i=0;i<a;i++){
            m*=(n-i+mod)%mod;
            m%=mod;
            m*=modpower((a-i+mod)%mod, mod-2)%mod;
            m%=mod;
        }
        m+=1;
        m%=mod;
        
        cout<<n<<" "<<m<<"\n";
    }
}