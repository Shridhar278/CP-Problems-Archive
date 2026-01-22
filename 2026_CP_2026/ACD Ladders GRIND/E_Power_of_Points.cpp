#include<bits/stdc++.h>
using namespace std;
const int N=200005;
pair<int,int>x[N];
long long a[N];

// good MATH

// excellent use of PREFIX SUM
// sorting was a NESSECITY HERE
// vector<vector<int>> of Nx2 reqr. to retain indices USE henceforth
// use that store via the retained indices in a NEW ARRAY
// +++X----- via total sum and prefix SUM cummulative till X add up
// NiCEE

int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        long long s1=0,s2=0;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i].first;
            x[i].second=i;
            s2+=x[i].first;
        }
        sort(x+1,x+n+1);
        for(int i=1;i<=n;i++)
        {
            s2-=x[i].first; // very NICE
            s1+=x[i].first; // wonderful
            a[x[i].second]=n+1ll*x[i].first*(2*i-n)-s1+s2;
        }
        for(int i=1;i<=n;i++)cout<<a[i]<<" \n"[i==n];
    }
}