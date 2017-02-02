#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
#define repd(i, j, k)for(int i=j;i>k;i--)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()

int a[200005];
int n;
using ll = long long;
ll dp[200005];

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;

        repi(i, 0, n)
                cin >> a[i];

        sort(a, a+n);

        memset(dp, 0, sizeof dp);

        ll ans = -1<<30;

        repi(i, 0, n) {
                repi(j, i, n) {
                        dp[i]+=(a[j]/a[i])*a[i];
                }
                ans = max(ans, dp[i]);
        }

        cout << ans << "\n";

        return 0;
}
