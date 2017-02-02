#include <bits/stdc++.h>

using namespace std;

double const eps=1e-8;
using ll = long long;
using ii = pair<int, int>;
#define rep(i, j, k)for(int i=j;i<k;++i)
#define pb push_back
#define ins insert
#define mp make_pair
#define eb emplace_back
#define all(x) x.begin(),x.end()

int n, m;
string grid[510];
bool visited[510][510];
bool weird[510][510];
bool impossible;

void dfs(int y, int x)
{
        vector<ii> possibs {ii(y+1, x), ii(y-1, x), ii(y, x-1), ii(y, x+1) };
        visited[y][x]=1;
        vector<ii> forbidden {ii(y+1, x+1), ii(y-1, x+1), ii(y+1, x-1), ii(y-1, x-1) };
        for (auto it : forbidden) {
                if (it.first<0 || it.second<0 || it.first>=n || it.second>=m)
                        continue;
                else {
                        if (grid[it.first][it.second]=='.')
                                weird[it.first][it.second]=true;
                }
        }
        for (auto it : possibs) {
                if (it.first<0 || it.second<0 || it.first>=n || it.second>=m)
                        continue;
                if (weird[it.first][it.second]==true) {
                        impossible=true;
                        return;
                }
                if (visited[it.first][it.second])
                        continue;
                if (grid[it.first][it.second]=='X') {
                        dfs(it.first, it.second);
                }
        }
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> m;
        rep(i, 0, n) {
                cin >> grid[i];
        }
        memset(visited, 0, sizeof visited);
        memset(weird, 0, sizeof weird);
        bool did=false;
        impossible=false;
        rep(i, 0, n) {
                rep(j, 0, m) {
                        if (impossible) {
                                cout << "NO\n";
                                return 0;
                        }
                        if (grid[i][j]!='X')
                                continue;
                        if (!visited[i][j]) {
                                if (did==true) {
                                        cout << "NO\n";
                                        return 0;
                                }
                                dfs(i, j);
                                did=true;
                        }
                }
        }
        cout << "YES\n";
        return 0;
}
