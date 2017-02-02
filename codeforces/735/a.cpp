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

int n;
int k;
string grid;
int visited[200];

bool solve(int idx)
{
        if (grid[idx]=='#')
                return false;
        if (grid[idx]=='T') {
                return true;
        }
        int ans=0;
        if (idx-k >= 0) {
                if (visited[idx-k]==0) {
                        visited[idx-k]=1;
                        ans = max(ans, (int)solve(idx-k));
                }
        }
        if (idx+k < n) {
                if (visited[idx+k]==0) {
                        visited[idx+k]=1;
                        ans = max(ans, (int)solve(idx+k));
                }
        }
        return ans;
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> k;
        cin >> grid;
        int len=grid.size();
        bool solvable=true;
        memset(visited, 0, sizeof visited);
        rep(i, 0, len) {
                if (grid[i]=='G') {
                        solvable=solve(i);
                        break;
                }
        }

        if (solvable)
                cout << "YES\n";
        else
                cout << "NO\n";
        return 0;
}
