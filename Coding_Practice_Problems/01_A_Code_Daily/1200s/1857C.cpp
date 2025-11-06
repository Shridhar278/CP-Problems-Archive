# include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

ll nc2(ll n) {
    return n * (n - 1) / 2;
}

ll solve_for_a(ll cnt, ll n) {
    if (cnt == nc2(n)) {
        return 1;
    }
    ll a = 2;
    while (nc2(a) != nc2(n) - cnt) {
        // cout<<a<<" "<<cnt<<" "<<n<<endl;
        a++;
    }
    a = n - a;
    return a;
}


int main() {
    int test;
    cin >> test;
    while (test--) {
        ll n;
        cin >> n;
        vector<ll> mins;
        for (int i = 0; i < nc2(n); i++) {
            ll x; cin >> x;
            mins.push_back(x);
        }
        sort(mins.begin(), mins.end());
        ll old = mins[0], cnt = 1, rem=n;
        vector<ll> ans;
        for (ll i = 1; i < nc2(n); i++) {
            // cout<<"%"<<mins[i]<<endl;
            if (mins[i] == old) {
                // cout<<"#"<<endl;
                cnt++;
            } else {
                ll a = solve_for_a(cnt, rem);
                // cout<<"$"<<old<<" "<<cnt<<" "<<a<<endl;
                ans.push_back(old);
                ans.push_back(a);
                rem -= a;
                cnt=1; old = mins[i];
                // cout<<"#"<<endl;
            }
        } ans.push_back(mins[nc2(n)-1]); ans.push_back(rem);
        for (int i=0;i<ans.size()-1; i+=2) {
            for (int j=0;j<ans[i+1];j++) {
                cout<<ans[i]<<" ";
            }
        }
    }
    return 0;
}