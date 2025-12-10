#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Question INTERPRATED WRONG: WTH are they asking ?

/* You cannot rotate the given rectangles to make them fit into the box.
   Moreover, any two distinct rectangles must not overlap, i. e.,
   any two distinct rectangles must have zero intersection area. */

// finally got it WHAT are they saying :)
// i can place rectangles of different widths over each other that is allowed..


// DONE SOLVED :D
/* this freaking question took me 8 hours to literally UNDERSTAND what is being asked,
 why can't they just state it more clearly !!! */

 // ist power of 2 Magneficio every small stuff 
 // can be added together for a big stuff hence, optimization possible 

int32_t main() {
    fast_io();
    int test, num;
    cin >> test;
    while (test--) {
        // This ONE is MESSED UP
    //     int n, w; cin >> n >> w;
    //     int space = w;
    //     vector<int> rects(20, 0);
    //     for (int i=0;i<n;i++) {
    //         cin >> num;
    //         rects[ilogb(num)]++;
    //     }
    //     vector<int>maxes; int max_count=0;
    //     for (int i=0;i<20;i++) {
    //         if (rects[i]!=0) {
    //             space-=(int)pow(2, i);
    //         }
    //         if (rects[i]==max_count) {
    //             maxes.push_back(i);
    //         } else if (rects[i] > max_count) {
    //             max_count=rects[i];
    //             maxes.clear();
    //             maxes.push_back(i);
    //         }
    //         // cout<<rects[i]<<" "<<max_count<<" "<<maxes.back()<<endl;
    //     }
    //     int one_stage_down = 0;
    //     for (auto ele: maxes) {
    //         // cout<<ele<<endl;
    //         one_stage_down+=(int)pow(2, ele);
    //     }
    //     // MAXIMUM - max.decrease in MAXIMUM from available SPACE
    //     int min_height = max_count-space/one_stage_down;
    //     if (min_height < 1) {
    //         min_height = 1;
    //     }
    //     cout<<min_height<<endl; 
        
        // QUESTION wasn't that clear and hence, answer to a different problem
        // THIS WAS A MUCH HARDER PROBLEM
        // the CORRECT efficient WAY
    //     int n, w, ele; cin >> n >> w;
    //     int space = w;
    //     vector <int> rects(20, 0);
    //     for (int i=0;i<20;i++) {
    //         rects[i]=i;
    //     }
    //     for (int i=0;i<n;i++) {
    //         cin >> ele;
    //         rects[ilogb(ele)]+=INF;
    //     }
    //     sort(rects.begin(), rects.end(), greater<int>());
    //     int max_count = rects.front()/INF;
    //     vector<int> steps = {0};
    //     int curr_max = max_count;
    //     for (int i=0;i<20;i++) {
    //         cout<<rects[i]<<" "<<curr_max<<" "<<steps.back()<<" "<<space<<endl;
    //         if (rects[i]/INF == curr_max) {
    //             steps[steps.size()-1]+=(int)pow(2, rects[i]%INF);
    //         } else {
    //             for (int j=1;j<curr_max-rects[i]/INF;j++) {
    //                 steps.push_back(steps.back());
    //             }
    //             curr_max=rects[i]/INF;
    //             if (rects[i]/INF==0) {
    //                 break;
    //             }
    //             steps.push_back(steps.back()+(int)pow(2, rects[i]%INF));
    //         }
    //         space-=(int)pow(2, rects[i]%INF);
    //     }
    //     int reduced_max = max_count;
    //     for(;reduced_max>1;reduced_max--) {
    //         cout<<space<<endl;
    //         space -= steps[max_count-reduced_max];
    //         if (space < 0) {
    //             break;
    //         }
    //     }
    //     cout<<reduced_max<<endl;
        
        // NOW onto the RIGHT PATH
        // greedy optimization
        int n, w, ele; cin >> n >> w;
        int space = w;
        vector <int> rects(20, 0);
        int max_log2 = 0, ttl_rects = 0;
        for (int i=0;i<n;i++) {
            cin >> ele;
            ttl_rects++;
            if (ilogb(ele) > max_log2) {
                max_log2 = ilogb(ele);
            }
            rects[ilogb(ele)]++;
        }
        int curr_width = w;
        int height = 0;
        while (ttl_rects > 0) {
            height++;
            for (int i=max_log2;i>=0;i--) {
                // cout<<rects[i]<<" "<<(int)pow(2, i)<<" "<<curr_width<<" "<<height<<" "<<ttl_rects<<endl;
                if (rects[i] > 0 && curr_width >= (int)pow(2, i)) {
                    curr_width -= (int)pow(2, i);
                    rects[i]--;
                    ttl_rects--;
                    i++; // to HOLD-on aur aane do
                }
            }
            curr_width = w;
        }
        cout<<height<<endl;
    }
    return 0;
}