#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // hello_world();
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n, m, x; cin >> n >> m;
        vector <int> sword;
        vector <int> life;
        vector <int> reinforce;
        int kills = 0;
        for (int i=0;i<n;i++) {
            cin >> x; sword.push_back(x);
        }
        for (int i=0;i<m;i++) {
            cin >> x; life.push_back(x);
        }
        for (int i=0;i<m;i++) {
            cin >> x; reinforce.push_back(x);
        }
        // search for MAX profit WHEN ONLY LOSS THEN SUDDEN DEATH MODE

        // I AM TIRED, will try after the contest
        // Good Night, Sweet Dreams
        sort(sword.begin(), sword.end());
        for (int i=0;i<n;i++) {
            int mx = 0, some=0, curr=0, ind;
            cout<<"Sword: "<<sword[i]<<endl;
            for (int j=0;j<m;j++) {
                cout<<sword[i]<<" "<<life[j]<<" "<<reinforce[j]<<endl;
                if (sword[i] >= life[j] && sword[i]<=reinforce[j]) {
                    cout<<"Chance: "<<life[j]<<" "<<reinforce[j]<<endl;
                    some = 1; curr = reinforce[j]-sword[i]; 
                    if (mx<=curr) {
                        mx=curr;
                        ind=j;
                    }
                }
            }
            if (some) {
                cout<<"Killing: "<<life[ind]<<" with sword "<<sword[i]<<endl;
                sword.erase(sword.begin()+i);
                life.erase(life.begin()+ind);
                if (reinforce[ind] >0) {
                    cout<<"Reinforcing sword with "<<reinforce[ind]<<endl;
                    sword.push_back(reinforce[ind]); n++;
                }
                reinforce.erase(reinforce.begin()+ind);
                kills++;
                sort(sword.begin(), sword.end());
                m--;
                n--;
                i--;
            }
        }
        if (m==0) {
            cout<<kills<<endl;
            continue;
        }
        // a heck lot of cases
        // again opt MAX PROFIT
        for (int i=n-1;i>=0;i--) {
            cout<<m<<"*"<<endl;
            if (m==0) 
                break;
            int mx = -INF, some=0, curr=0, ind, dead=-INF, mxdead=-INF;
            cout<<"Sword: "<<sword[i]<<endl;
            for (int j=0;j<m;j++) {
                cout<<sword[i]<<" "<<life[j]<<" "<<reinforce[j]<<endl;
                if (sword[i] >= life[j]) {
                    cout<<"Chance: "<<life[j]<<" "<<reinforce[j]<<endl;
                    some = 1; curr = reinforce[j]-sword[j];
                    dead = life[j]-sword[i];
                    if (dead > mxdead) {
                        if (mx<=curr) {
                            mxdead = dead;
                            mx=curr;
                            ind = j;
                        }
                    }
                }
            }
            if (some) {
                cout<<"Killing: "<<life[ind]<<" with sword "<<sword[i]<<endl;
                sword.erase(sword.begin()+i);
                life.erase(life.begin()+ind);
                if (reinforce[ind] >0) {
                    cout<<"Reinforcing sword with "<<reinforce[ind]<<endl;
                    sword.push_back(reinforce[ind]); i++;
                }
                reinforce.erase(reinforce.begin()+ind);
                kills++;
                sort(sword.begin(), sword.end());
                m--;
            }
        }


        // for (int i=n-1;i>=0;i--) {
        //     cout<<m<<"*"<<endl;
        //     if (m==0) 
        //         break;
        //     int x = max_element(life.begin(), life.end())-life.begin();

        //     cout<<sword[i]<<" "<<life[x]<<" "<<m<<endl;
        //     if (sword[i] >= life[x]) {
        //         cout<<"a"<< endl;
        //         sword.erase(sword.begin()+i);
        //         life.erase(life.begin()+x);
        //         if (reinforce[x] >0) {
        //             sword.push_back(reinforce[x]); i++;
        //         }
        //         reinforce.erase(reinforce.begin()+x);
        //         kills++;
        //         sort(sword.begin(), sword.end());
        //         n--;
        //         m--;
        //     } else{
        //         cout<<"b"<<endl;
        //         life.erase(life.begin()+x);
        //         reinforce.erase(reinforce.begin()+x);
        //         i++;
        //         m--;
        //     }
        // }
        cout<<kills<<endl;
    }
    return 0;
}