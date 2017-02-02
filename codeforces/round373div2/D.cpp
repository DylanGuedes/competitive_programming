#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int t[200005];
int n, m;

int solve(int idx, int copies)
{
        if (copies == 0)
                return 0;
        if (idx == n)
                return 0;
        int ans = 1<<30;
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> m;
        FOR(i, 0, n)
                cin >> t[i];
        int copies;
        FOR(i, 0, m) {
                cin >> copies;
                cout << solve(0, copies) << "\n";
        }
        return 0;
}
