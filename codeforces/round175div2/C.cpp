#include <bits/stdc++.h>

using namespace std;

int arr[500000];
#define rep(i, j, k)for(int i=j;i<k;++i)
using ll = long long;

int main()
{
        ios::sync_with_stdio(false);
        int n, idx;
        cin >> n;
        memset(arr, 0, sizeof arr);
        rep(i, 0, n) {
                cin >> arr[i];
        }

        sort(arr, arr+n);

        ll cnt=0;
        rep(i, 0, n) {
                cnt+=(abs(i+1-arr[i]));
        }

        cout << cnt << "\n";

        return 0;
}
