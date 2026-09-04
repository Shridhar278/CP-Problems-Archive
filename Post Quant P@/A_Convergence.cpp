#include <bits/stdc++.h>
#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t = 1;
	cin >> t;
    while(t-->0)
    {
        int n;
        cin >> n;

        vi a(n);
        for(int i=0; i<n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        int cnt = 0;
        for(int i=0; i<n; i++) if(a[i] != a[n-1-i]) cnt++;

        cout << cnt / 2 << "\n";
    }
}

// last time NOW, getting back tomorrow to CP