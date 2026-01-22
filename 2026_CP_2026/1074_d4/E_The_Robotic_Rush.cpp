#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> robot(n);
    vector<int> spike(m);
    string inst;
    for (int i=0;i<n;i++) {
        cin >> robot[i];
    }
    sort(robot.begin(), robot.end());
    for (int i=0;i<m;i++) {
        cin >> spike[i];
    }
    sort(spike.begin(), spike.end());
    cin >> inst;
    int r=0, s=0;
    vector<vector<int>> right;
    vector<vector<int>> left;
    while(r<n && s<m) {
        if (robot[r]<spike[s]) {
            if (s==0) {
                left.push_back({MOD, r, 1});
            } else {
                left.push_back({robot[r]-spike[s-1], r, 1});
            }
            right.push_back({spike[s]-robot[r], r, 1});
            r++;
        } else {
            left.push_back({robot[r]-spike[s], r, 1});
            if (s==m-1) {
                right.push_back({MOD, r, 1});
            } else {
                int xy;
                for (xy=s;xy<m;xy++) {
                    if (spike[xy]>robot[r]) {
                        break;
                    }
                }
                if (xy==m) {
                    s=m-1;
                    right.push_back({MOD, r, 1});
                } else {
                    s=xy;
                    right.push_back({spike[s]-robot[r], r, 1});
                }
            }
            r++;
        }
    }
    sort(right.begin(), right.end());
    sort(left.begin(), left.end());
    int r_alive=0, l_alive=0;
    int kills=0;
    int pos=0;
    for (int i=0;i<k;i++) {
        // cout<<n<<" "<<kills<<" "<<l_alive<<" "<<r_alive<<" "<<pos<<endl;
        // cout<<right[r_alive][0]<<" "<<right[r_alive][1]<<" "<<right[r_alive][2]<<endl;
        // cout<<left[l_alive][0]<<" "<<left[l_alive][1]<<" "<<left[l_alive][2]<<endl;
        // cout<<"$"<<endl;
        if (inst[i]=='R') {
            pos++;
            if (pos==right[r_alive][0] && right[r_alive][2]==1) {
                int j=r_alive;
                for (;j<n;j++) {
                    if (right[j][0] > pos) {
                        break;
                    }
                    right[j][2]=0;
                    left[right[j][1]][2]=0;
                    kills++;
                }
                r_alive=j-1;
            }
        } else {
            pos--;
            if (-pos==left[l_alive][0] && left[l_alive][2]==1) {
                int j=l_alive;
                for (;j<n;j++) {
                    if (left[j][0] > -pos) {
                        break;
                    }
                    left[j][2]=0;
                    right[left[j][1]][2]=0;
                    kills++;
                }
                l_alive=j-1;
            }
        }
        cout<<n-kills<<" ";
    }
    // cout<<n-kills<<" ";
    cout<<endl;
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