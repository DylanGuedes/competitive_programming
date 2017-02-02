#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
#define repd(i, j, k)for(int i=j;i>=k;i--)
#define pb(i) push_back(i)

using ll = int;
using ii = pair<ll, ll>;

vector<pair<ll, ll> > graph[5010];
int parent[5010];
ll T;

void dfs(int idx, int len)
{
        if (parent[idx] == idx){
                cout << len << "\n";
                cout << idx+1;
        } else {
                dfs(parent[idx], len+1);
                cout << " " << idx+1;
        }
}

void dfs2(int idx, int val)
{
        for (auto it : graph[idx]) {
                if (it.first+val <= T) {
                        parent[it.second] = idx;
                        dfs2(it.second, val);
                }
        }
}

void bfs(int origin, int destination)
{
        dfs2(origin, 0);

        dfs(destination, 1);
        cout << "\n";
}

int main()
{
        ios::sync_with_stdio(false);
        int n, m;
        int origin, destination, weight;
        cin >> n >> m >> T;
        repi(i, 0, m) {
                cin >> origin >> destination >> weight;
                graph[origin-1].emplace_back(weight, destination-1);
        }
        repi(i, 0, n+2)
                parent[i] = i;
        bfs(0, n-1);
        return 0;
}
