#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
#define all(x) x.begin(), x.end()
using ll = long long;
using ii = pair<int, int>;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define emp emplace
#define ins insert

int grid[1010][1010];

int main()
{
        ios::sync_with_stdio(false);
        int n, m;
        cin >> n >> m;
        rep(i, 0, n) {
                rep(j, 0, m) {
                        cin >> grid[i][j];
                        row[i]++;
                        column[j]++;
                }
        }
        return 0;
}
