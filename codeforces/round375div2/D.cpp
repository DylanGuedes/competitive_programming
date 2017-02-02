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
int w, h;

char grid[55][55];

int visited[55][55];

void dfs2(int x, int y)
{
        visited[y][x] = 1;
        vector<ii> myv {ii(x+1, y), ii(x-1, y), ii(x, y+1), ii(x, y-1) };
        for (auto it : myv) {
                if (it.first < 0 || it.second < 0 || it.first >= w || it.second >= h)
                        continue;
                if (grid[it.second][it.first] != '.')
                        continue;
                grid[it.second][it.first] = '*';
                dfs2(it.first, it.second);
        }
}

void dfs(int x, int y)
{
        visited[y][x] = 1;
        vector<ii> myv {ii(x+1, y), ii(x-1, y), ii(x, y+1), ii(x, y-1) };
        for (auto it : myv) {
                if (it.second < 0 || it.first < 0 || it.second >= h ||  it.first >= w)
                        continue;
                if (visited[it.second][it.first])
                        continue;
                if (grid[it.second][it.first] != '.')
                        continue;

                dfs(it.first, it.second);
        }
}

vector< pair<int, ii> > q;

int dfs3(int x, int y)
{
        visited[y][x] = 1;
        vector<ii> myv {ii(x, y+1), ii(x, y-1), ii(x+1, y), ii(x-1, y) };
        int resp = 0;
        for (auto it : myv) {
                if (it.first < 0 || it.second < 0 || it.second >= h || it.first >= w) {
                        continue;
                }
                if (visited[it.second][it.first])
                        continue;
                if (grid[it.second][it.first] != '.')
                        continue;
                resp += 1+dfs3(it.first, it.second);
        }
        return resp;
}

bool myfunc(pair<int, ii> p1, pair<int, ii> p2)
{
        return p1.first > p2.first;
}

int main()
{
        ios::sync_with_stdio(false);
        int n, m, k;
        cin >> n >> m >> k;

        repi(i, 0, n) {
                repi(j, 0, m) {
                        cin >> grid[i][j];
                }
        }

        memset(visited, 0, sizeof visited);
        w = m;
        h = n;

        repi(i, 0, w) {
                if (grid[0][i] == '.' && not visited[0][i])
                        dfs(i, 0);

                if (grid[h-1][i] == '.' && not visited[h-1][i])
                        dfs(i, h-1);
        }

        repi(i, 0, h) {
                if (grid[i][0] == '.' && not visited[i][0])
                        dfs(0, i);
                if (grid[i][w-1] == '.' && not visited[i][w-1])
                        dfs(w-1, i);
        }

        repi(i, 0, n) {
                repi(j, 0, m) {
                        if (visited[i][j])
                                continue;
                        if (grid[i][j] != '.')
                                continue;
                        int val = dfs3(j, i)+1;
                        q.emplace_back(val, ii(j, i));
                }
        }

        sort(q.begin(), q.end(), myfunc);
        memset(visited, 0, sizeof visited);
        int total = 0;
        while (not q.empty() && q.size()!=k) {
                ii pos = q.back().second;
                grid[pos.second][pos.first] = '*';
                total += q.back().first;
                dfs2(pos.first, pos.second);
                q.pop_back();
        }

        cout << total << "\n";

        repi(i, 0, n) {
                repi(j, 0, m) {
                        cout << grid[i][j];
                }
                cout << "\n";
        }

        return 0;
}
