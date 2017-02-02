#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
#define pb push_back
using ll = long long;
vector<int> myv;
ll k;

ll myfunc(ll val1, ll val2, ll val3)
{
        if (val3 > 50)
                return 0;
        if (k%val1 == val2) {
                return val3;
        } else {
                myfunc(val1*2, val2*2, val3+1);
        }
}

int main()
{
        ios::sync_with_stdio(false);
        ll n;
        cin >> n>> k;
        if (k&1) {
                cout << 1 << "\n";
        } else {
                if (k==2) {
                        cout << 2 << "\n";
                } else {
                        cout << myfunc(4, 2, 2) << "\n";
                }
        }
        return 0;
}
