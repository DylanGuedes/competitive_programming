#include <bits/stdc++.h>

using namespace std;

double const eps=1e-8;
using ll = long long;
using ii = pair<int, int>;
#define rep(i, j, k)for(int i=j;i<k;++i)
#define FOR(i, j, k)for(int i=j;i<k;++i)
#define pb push_back
#define ins insert
#define mp make_pair
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define debug(x) cout << #x << " = " << x << endl

#define MAX 100010
int n, m;
string str;
int arr[MAX];
int dp[MAX];

int main()
{
        ios::sync_with_stdio(false);

        cin >> n;

        rep(i, 0, n) {
                cin >> arr[i];
                if (i>1) {
                        if (arr[i]>arr[i-1] && arr[i-1]<arr[i-2]) {
                                dp[i]=dp[i-1]+1;
                        } else if (arr[i]<arr[i-1] && arr[i-1]>arr[i-2]) {
                                dp[i]=dp[i-1]+1;
                        } else if (arr[i]<arr[i-1] || arr[i-1]<arr[i]) {
                                dp[i]=2;
                        } else {
                                dp[i]=1;
                        }
                } else if (i==1) {
                        if (arr[i]>arr[i-1] || arr[i]<arr[i-1]) {
                                dp[i]=2;
                        }
                } else if (i==0) {
                        dp[i]=1;
                }
        }

        int ans=-1<<30;
        rep(i, 0, n) {
                ans=max(ans, dp[i]);
        }

        cout << ans << "\n";

        return 0;
}
