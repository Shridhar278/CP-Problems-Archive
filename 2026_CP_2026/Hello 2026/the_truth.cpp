#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int solveE(int n, int m, int k) {
    if(k-1<n-k)k=n+1-k;
    int a=0,b=0;
    while(1){
        if(b<n-k&&a+(b+1)+max(a,b+1)-1<=m)++b;
        if(a<k-1&&(a+1)+b+max(a+1,b)-1<=m)++a;
        else break;
    }
    return a+b+1;
}

int solveC(int n, int m, int k) {
    int a = k-1, b = n-k;
    a = (a >= b) ? a : b;
    b = n-1-a;
    int best_b=(m+1)/3, best_a=(m+2)/3;
    if (best_b>b) {
        best_b=b;
        best_a=min((m+1-best_b)/2, a);
    }
    if (best_a>a) {
        best_a=a;
        best_b=min(m+1-2*best_a, b);
    }
    return best_a+best_b+1;
}

int32_t main() {
    fast_io();
    for (int n=1;n<=100;n++) {
        for (int m=1;m<=3*n;m++) {
            for (int k=1;k<=n;k++) {
                int x = solveC(n, m, k);
                int y = solveE(n, m, k);
                if (x!=y) {
                    cout<<"n: "<<n<<" m: "<<m<<" k: "<<k<<" CONTEST: "<<x<<" CORRECT: "<<y<<"\n";
                }
            }
        }
    }
    cout<<"THE END"<<endl;
    return 0;
}