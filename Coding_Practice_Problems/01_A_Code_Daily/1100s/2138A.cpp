#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int up_the_tree(ll, ll, int*, int);
int main() {
    int test, k;
    ll x;
    cin >> test;
    for (int t = 1; t <= test; t++) {
        cin >> k >> x;
        int acts[k];
        int size = up_the_tree(x, (ll)pow(2,k+1)-x, acts, 0);
        cout<<size<<endl;
        for (int i=size-1; i>=0; i--) {
            cout << acts[i] << " ";
        }
        cout<<endl;
    }
    return 0;
}

int up_the_tree(ll c, ll v, int* acts, int size) {
    if (v==c) {
        return size;
    } else {
        if (v < c) {
            acts[size] = 2;
            size++;
            return up_the_tree(c/2-v/2, v, acts, size);

        } else {
            acts[size] = 1;
            size++;
            return up_the_tree(c, v/2-c/2, acts, size);
        }
    }
}