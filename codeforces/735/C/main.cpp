#include <bits/stdc++.h>

using namespace std;

#define rep(i, j,k )for(int i=j;i<k;++i)

using ll = unsigned long long;
ll dp[150];

int main()
{
        ios::sync_with_stdio(false);
        ll n;
        cin >> n;
        dp[0]=1;
        dp[1]=2;
        int i=2;
        for (; dp[i-1]<=n;++i) {
                dp[i]=dp[i-1]+dp[i-2];
        }
        cout << i-2 << "\n";
        return 0;
}
