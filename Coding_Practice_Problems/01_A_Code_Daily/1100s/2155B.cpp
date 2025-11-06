#include <bits/stdc++.h>

using namespace std;

void solve(int n, int k) {
    int i=0, j=0;
    bool right=true;
    while (i!=n) {
        if (i*n+j<k) {
            cout<<"U";
        } else if (i==n-1 && j == n-1 && right) {
            cout<<"L";
        } else if (i==n-1 && j == 0 && left){
            cout<<"R";
        } else if (right == true) {
            if (j==n-1) {
                cout<<"D";
                right=false;
            } else {
                cout<<"R";
            }
        } else {
            if (j==0) {
                cout<<"D";
                right=true;
            } else {
                cout<<"L";
            }
        }
        j++;
        if (j==n) {
            cout<<endl;
            i++;
            j=0;
        }
    }
}

int main(){
    int test, n, k;
    cin>>test;
    for (int i=0;i<test;i++){
        cin>>n>>k;
        if (k==n*n-1) {
            cout<<"NO\n";
        } else {
            cout<<"YES\n";
            solve(n, k);
        }
    }
    return 0;
}