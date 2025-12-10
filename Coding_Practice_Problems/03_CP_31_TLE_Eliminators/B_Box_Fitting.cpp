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
    int test, num;
    cin >> test;
    while (test--) {
        // This ONE is MESSED UP
        // int n, w; cin >> n >> w;
        // int space = w;
        // vector<int> rects(20, 0);
        // for (int i=0;i<n;i++) {
        //     cin >> num;
        //     rects[ilogb(num)]++;
        // }
        // vector<int>maxes; int max_count=0;
        // for (int i=0;i<20;i++) {
        //     if (rects[i]!=0) {
        //         space-=(int)pow(2, i);
        //     }
        //     if (rects[i]==max_count) {
        //         maxes.push_back(i);
        //     } else if (rects[i] > max_count) {
        //         max_count=rects[i];
        //         maxes.clear();
        //         maxes.push_back(i);
        //     }
        //     // cout<<rects[i]<<" "<<max_count<<" "<<maxes.back()<<endl;
        // }
        // int one_stage_down = 0;
        // for (auto ele: maxes) {
        //     // cout<<ele<<endl;
        //     one_stage_down+=(int)pow(2, ele);
        // }
        // // MAXIMUM - max.decrease in MAXIMUM from available SPACE
        // int min_height = max_count-space/one_stage_down;
        // if (min_height < 1) {
        //     min_height = 1;
        // }
        // cout<<min_height<<endl; 
        
        // the CORRECT efficient WAY
        int n, w, ele; cin >> n >> w;
        int space = w;
        vector <int> rects(20, 0);
        for (int i=0;i<n;i++) {
            cin >> ele;
            space-=ele;
            rects[ilogb(ele)]+=INF;
        }
        sort(rects.begin(), rects.end());
        
    }
    return 0;
}