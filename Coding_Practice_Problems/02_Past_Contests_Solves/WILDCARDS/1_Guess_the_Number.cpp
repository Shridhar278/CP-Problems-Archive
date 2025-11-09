#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int st=1, ed=1000000;
    int mid =(st+ed)/2;
    string res;
    while (st<ed) {
        mid =(st+ed+1)/2;
        cout<<mid<<endl;
        cout<<flush;
        cin>>res;
        if (res=="<") {
            ed=mid-1;
        } else {
            st=mid;
        }
    }
    cout<<"! "<<st<<endl;
    cout<<flush;
    return 0;
}