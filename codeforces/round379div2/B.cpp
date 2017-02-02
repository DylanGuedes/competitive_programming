#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
#define all(x) x.begin(), x.end()
using ll = long long;
using ii = pair<int, int>;
#define repd(i, j, k)for(int i=j;i>=k;i--)
#define pb push_back
#define eb emplace_back
#define emp emplace
#define ins insert
#define mp make_pair
double const eps = 1e-10;
double const pi = acos(-1);

int arr[5];

int main()
{
        ios::sync_with_stdio(false);

        ll k2, k3, k5, k6;
        cin >> k2 >> k3 >> k5 >> k6;

        ll val256 = min(k2, min(k5, k6));
        k2 -= val256;
        k5 -= val256;
        k6 -= val256;

        ll val32 = min(k3, k2);

        ll total = 256*(val256) + 32*val32;

        cout << total << "\n";

        return 0;
}
