#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Perfecto // SOLVED MINIMALISTIC ALGORITHM found # DONE

int32_t main() {
    fast_io();
    char str[200001];
    cin >> str; int len = strlen(str);    
    int i=1;
    char res[200001];
    strcpy(res, str);
    while (i < len) {
        if (str[i]==str[i-1]) {
            if (i==len-1) {
                if (res[i]=='z') {
                    res[i]='a';
                } else {
                    res[i]+=1;
                }
                break;
            }
            if (str[i]==str[i+1]) {
                if (res[i]=='z') {
                    res[i]='a';
                } else {
                    res[i]+=1;
                }
            } else {
                if (max(str[i-1], str[i+1]) - min(str[i-1], str[i+1]) == 25) {
                    res[i]='b';
                } else if (max(str[i-1], str[i+1])==122) {
                    res[i]='a';
                } else {
                    res[i]=max(str[i-1], str[i+1])+1;   
                }
            }
            i+=2;
        } else {
            i++;
        }
    }
    cout<<res<<endl;
    return 0;
}