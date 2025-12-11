#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n; cin >> n;
        vector<int> arr(n);
        vector<int> evens={0};
        vector<int> odds={0};
        for (int i=0;i<n;i++) {
            cin >> arr[i];
            if (arr[i]%2) {
                odds.push_back(arr[i]);
            } else {
                evens.push_back(arr[i]);
            }
        }
        sort(odds.begin(), odds.end(), greater<int>());
        sort(evens.begin(), evens.end(), greater<int>());
        
        //too situational
        // int trend; // 0 is for ODD 1 is for EVEN
        // vector<int> scores;
        // int carry_odd, evenO, oddO;
        // int carry_even, evenE, oddE;
        // for (int k=1;k<n;k++) {
        //     if (k==1) {
        //         scores.push_back(odds.front());
        //     } else if (k==2) {
        //         scores.push_back(odds.front()+evens.front());
        //     } else if (k==3) {
        //         scores.push_back(max(odds[0]+odds[1]+odds[2], odds[0]+evens[0]+evens[1]));
        //         if (odds[0]+odds[1]+odds[2]>=odds[0]+evens[0]+evens[1]) {
        //             trend = 0;
        //             evenO=0;
        //             oddO=3;
        //         } else {
        //             trend = 1;
        //             evenO=2;
        //             oddO=1;
        //         }
        //         carry_odd = scores.back();
        //     } else if (k==4) {
        //         scores.push_back(max(odds[0]+evens[0]+odds[1]+odds[2], odds[0]+evens[0]+evens[1]+evens[2]));
        //         if (odds[0]+odds[1]+odds[2]>=odds[0]+evens[0]+evens[1]) {
        //             trend = 0;
        //             evenO=0;
        //             oddO=3;
        //         } else {
        //             trend = 1;
        //             evenO=2;
        //             oddO=1;
        //         }
        //         carry_odd = scores.back();
        //     }
        // }
        // 
        // for (int k=0;k<n;k++) {
        //     cout<<scores[k]<<" ";
        // }
        // cout << endl;
        
        vector <int> scores={0};
        int o1=1, o2=1, e1=1, e2=1;
        int oes=0, ees=0;
        // extreme SPECIAL cases ADD eventually 
        // first few cases add myself;
        if (odds.size()==0) {
            for (int k=0;k<n;k++) {
                cout<<0<<" ";
            }
            cout << endl;
            continue;
        } else if (evens.size()==0) {
            // GIVE UP
        }
        // the general SOLVE
        int oX=oes+odds[o2-1]+odds[o2], eX=ees+evens[e2-1]+evens[e2];
        for (int k=3;k<n;k++) {
            if (k%2==1) {
                if (oX >= eX) {
                    o1+=2; o2+=2;
                    e1-=1; e2-=1;
                    oes+=odds[o1-1]+odds[o1];
                    ees-=evens[e1+1];
                } else {
                    e1+=1; e2+=1;
                    ees+=evens[e1];
                }
            } else {
                if (oX >= eX) {
                    o1+=2; o2+=2;
                    e1-=1; e2-=1;
                    oes+=odds[o1-1]+odds[o1];
                    ees-=evens[e1+1];
                } else {
                    e1+=1; e2+=1;
                    ees+=evens[e1];
                }
            }
            scores.push_back(max(oX, eX));
        }

        for (int k=0;k<n;k++) {
            cout<<scores[k]<<" ";
        }
        cout << endl;
    }
    return 0;
}