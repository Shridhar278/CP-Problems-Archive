#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// THIS FEELS perfect
// WILL WATCH EDITORIAL

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int head=0, tail=1;
    int X=0;
    int that_one=-1, pos, ttlx, sml, mini_head=0, pig;
    int this_one=-1, tiny, ttl;
    while(tail!=n) {
        // cout<<"#X="<<X<<" "<<sml<<endl;
        if (arr[head]>0) {
            if (arr[tail] > 0) {
                if (arr[tail] >= arr[head]) {
                    mini_head+=arr[head];
                } else {
                    mini_head=0;
                }
                X+=arr[head];
                head=tail;
                tail++;
            } else if (arr[tail] == 0) {
                tail++;
            } else {
                if (that_one<head) {
                    pos=0;
                    ttlx=0;
                    sml=-INF;
                    int j;
                    for (j=tail;j<n;j++) {
                        if (arr[j] >= 0) {
                            pos=1;
                            that_one=j;
                            break;
                        } else {
                            sml = max(sml, arr[j]);
                            if (sml==arr[j]) {
                                pig = j;
                            }
                            ttlx+=arr[j];
                        }
                    }
                    ttlx-=arr[n-1];
                }
                if (pos==0) {
                    // cout<<"$"<<sml<<" "<<arr[head]<<" "<<arr[tail]<<endl;
                    if (tail==pig) {
                        if (arr[head]>-sml) {
                            X+=arr[head];
                            head=tail;
                            tail++;
                        } else {
                            X-=arr[tail];
                            tail++;
                        }
                    } else {
                        X-=arr[tail];
                        tail++;
                    }
                    that_one=n;
                } else {
                    X-=arr[tail];
                    tail++;
                }
            }
        } else if (arr[head]==0) {
            if (arr[tail] > 0) {
                head=tail;
                tail++;
            } else if (arr[tail] == 0) {
                head=tail;
                tail++;
            } else {
                X-=arr[tail];
                tail++;
            }
        } else {
            if (arr[tail] > 0) {
                if (this_one<tail) {
                    ttl=0;
                    tiny=INF;
                    int i;
                    for (i=tail;i<n;i++) {
                        if (arr[i] > 0) {
                            ttl+=arr[i];
                            tiny = min(tiny, arr[i]);
                            if (tiny==arr[i]) {
                                this_one = i;
                            }
                        }
                    }
                    if (ttl==0) {
                        this_one=n;
                    }
                }
                if (-arr[head]<ttl) {
                    X+=arr[head];
                    head=tail;
                    tail++;
                } else {
                    X-=arr[tail];
                    tail++;
                }
            } else if (arr[tail] == 0) {
                tail++;
            } else {
                X-=arr[tail];
                tail++;
            }
        }
    }
    cout<<X<<endl;
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