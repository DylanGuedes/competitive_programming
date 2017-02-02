#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
using ii = pair<int, int>;
using ll = long long;
#define pb(i) push_back(i)
#define eb(i, j) emplace_back(i, j)

int n, m;
int visited[100020];
int cat[100020];
vector<int> graph[100020];

int dfs(int idx, int val, int parent)
{
        int total = 0;
        if (val > m)
                return 0;

        bool leaf = true;

        for (auto it : graph[idx]) {
                if (it == parent)
                        continue;
                leaf = false;
                if (cat[it] && val+1>m) {
                        continue;
                }
                total+=dfs(it, cat[it]*(1+val), idx);
        }

        return total+leaf;
}

int main()
{
        ios::sync_with_stdio(false);
        int origin, destination;
        int aux;
        cin >> n >> m;
        repi(i, 1, n+1) {
                cin >> aux;
                cat[i] = aux;
        }

        repi(i, 0, n-1) {
                cin >> origin >> destination;
                graph[origin].pb(destination);
                graph[destination].pb(origin);
        }

        cout << dfs(1, cat[1], 1) << "\n";
        return 0;
}
