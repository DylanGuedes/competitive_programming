#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define emp emplace
#define ins insert
#define rep(i, j, k)for(int i=j;i<k;++i)
#define DEBUG(arg, x) cout << arg << " => " << x << "\n"

using ii = pair<int, int>;
using ll = long long;

int n;
int arr[100005];
set<int> myset;

void solve(int idx, int val)
{
        if (idx==n)
                return;
        if (dp[idx][val] != -1)
                return dp[idx][val];
        myset.insert(arr[idx]);
        myset.insert(val&arr[idx]);
        solve(idx+1, val&arr[idx]);
        solve(idx+1, arr[idx]);
        solve(idx+1, val);
        dp[idx][val]=idx;
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;
        rep(i, 0, n)
                cin >> arr[i];
        memset(dp, -1, sizeof dp);
        solve(0, -1);

        myset.insert(0);
        cout << myset.size() << "\n";
        return 0;
}
