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

int val[200020];
vector<ii> graph[200020];
int n;
int domminates[200020];
int visited[200020];

void dfs(int idx)
{
        visited[idx] = 1;
        for (auto it : graph[idx]) {
                if (visited[it.second])
                        continue;
                if (
        }
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;
        rep(i, 0, n)
                cin >> val[i];
        int par, weight;
        rep(i, 1, n) {
                cin >> par >> weight;
                graph[par-1].eb(weight, i);
        }
        memset(domminates, 0, sizeof domminates);
        memset(visited, 0, sizeof visited);
        rep(i, 0, n) {
                if (not visited[i])
                        dfs(0);
        }
        rep(i, 0, n) {
                if (i)
                        cout << " ";
                cout << domminates[i];
        }
        return 0;
}
