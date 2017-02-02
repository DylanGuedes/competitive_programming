#include <bits/stdc++.h>
#ifdef JUDGE
std::ifstream fin("snowmen.in");
std::ofstream fout("snowmen.out");
#else
#define fin cin
#define fout cout
#endif

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)

using ll = long long;
vector<int> graph[1000010];
int parent[1000010];

int dfs(int idx, int topo, int aggr)
{
        visited[idx] = 1;
        total += aggr;
}

int main() {
        ios::sync_with_stdio(false);
        int n, m, t;
        ll total = 0;
        fin >> n;

        rep(i, 0, n) {
                fin >> t >> m;
                if (m) {
                        graph[t].pb(i);
                } else {
                        graph[parent[t]].pb(i);
                }
        }

        rep(i, 0, n+2) {
                parent[i] = i;
        }

        fout << dfs(0, 0, 0) << "\n";

        return 0;
}
