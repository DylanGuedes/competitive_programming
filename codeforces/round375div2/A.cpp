#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
#define repd(i, j, k)for(int i=j;i>=k;i--)
#define pb(i) push_back(i)
#define eb(i, j) emplace_back(i, j)
using ii = pair<int, int>;
using ll = long long;
using dd = pair<double, double>;
using pll = pair<ll, ll>;
double const eps = 1e-10;
double const pi = 3.141592653589793;

int main()
{
        ios::sync_with_stdio(false);
        int arr[3];
        int n;
        repi(i, 0, 3)
                cin >> arr[i];

        sort(arr, arr+3);

        cout << arr[2]-arr[0] << "\n";

        return 0;
}
