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
#define debug(x) cout << #x << " = " << x << endl

int n, m, foo, aux;
string str;
#define N 400000
vector<int> graph[N];
int col[N];
bool impossible;
int node;

void dfs(int, int, bool);

void dfs2(int idx, int parent, bool f)
{
        for (auto it : graph[idx]) {
                if (it==parent)
                        continue;
                dfs(it, idx, true);
        }
}

void dfs(int idx, int parent, bool f)
{
        if (impossible)
                return;

        for (auto it : graph[idx]) {
                if (it==parent)
                        continue;
                if (f) {
                        if (col[it]!=col[idx]) {
                                // debug(it);
                                // debug(idx);
                                impossible=true;
                                return;
                        } else {
                                dfs(it, idx, f);
                        }
                } else {
                        if (col[it]!=col[idx]) {
                                node=it+1;
                                f=true;
                                dfs2(it, idx, f);
                                f=false;
                        } else {
                                dfs(it, idx, f);
                        }
                }
        }
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;
        int u, v;
        rep(i, 0, n-1) {
                cin >> u >> v;
                graph[u-1].pb(v-1);
                graph[v-1].pb(u-1);
        }

        node=1;
        impossible=false;
        rep(i, 0, n) {
                cin >> col[i];
        }

        dfs(0, -1, false);
        if (impossible) {
                cout << "NO\n";
        } else {
                cout << "YES\n";
                cout << node << "\n";
        }
        return 0;
}
