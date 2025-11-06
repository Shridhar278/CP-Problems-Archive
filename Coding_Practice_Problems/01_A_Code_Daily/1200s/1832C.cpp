# include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ALWAYS CHECK EDGE CASES, MAXMIN VALUES, AND UNIQUE CASES
// kinda good habit to adapt to

// WTF this took so much time
// the question had so many edge cases to consider
// mainly because of the zeros and equalitys

int main() {
    int test;
    cin>>test;
    while(test--) {
        int n;
        cin>>n;
        ll prev, curr;
        int sign=0, zero=0;
        cin>>prev;
        int least=n;
        bool alpha;
        for(int i=0; i<n-1; i++) {
            alpha = false;
            cin>>curr;
            if (sign!=0 && zero==0) {
                alpha = true;
                // cout<<"%"<<curr<<" "<<prev<<" "<<least<<" "<<zero<<" "<<sign<<endl;
                if ((curr-prev)*sign > 0) {
                    least--;
                } else if ((curr-prev)*sign < 0) {
                    sign*=-1;
                } else {
                    least--;
                }
                if (curr==0) zero=1;
            }
            if (sign==0) {
                // cout<<"*"<<curr<<" "<<prev<<" "<<least<<" "<<zero<<" "<<sign<<endl;
                if (curr > prev) sign=1;
                else if (curr < prev) sign=-1;
                else least--;
                if (curr==0) {
                    zero=1;
                    least++;
                }
            }
            if (zero==1 && alpha==false) {
                // cout<<"$"<<curr<<" "<<prev<<" "<<least<<" "<<zero<<" "<<sign<<endl;
                zero=0;
                if (curr>0) sign=1;
                else if (curr<0) sign=-1;
                else {
                    least--;
                    zero=1;
                }
            }
            prev=curr;
        }
        cout<<least<<endl;
    }
}