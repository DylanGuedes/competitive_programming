#include <bits/stdc++.h>

using namespace std;


#define rep(i, j, k)for(int i=j;i<k;++i)
#define repd(i, j, k)for(int i=j;i>=k;i--)
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define ins insert
#define popb pop_back
using ii = pair<int, int>;
using ll = long long;
int n;
int crush[105];
vector<int> graph[150];
vector<int> rev[150];
int visited[150];
vector<int> scc_size;
stack<int> s;

void dfs(int idx)
{
        visited[idx]=1;
        for (auto it : graph[idx]) {
                if (visited[it])
                        continue;
                dfs(it);
        }
        s.push(idx);
}

void dfs2(int idx)
{
        visited[idx]=1;
        scc_size[scc_size.size()-1]++;
        for (auto it : rev[idx]) {
                if (visited[it])
                        continue;
                dfs2(it);
        }
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;

        int aux=0;

        memset(visited, 0, sizeof visited);
        rep(i, 0, n) {
                cin >> aux;
                graph[i].pb(aux-1);
                rev[aux-1].pb(i);
        }

        rep(i, 0, n) {
                if (!visited[i])
                        dfs(i);
        }


        memset(visited, 0, sizeof visited);

        int ans=-1<<30;
        while (not s.empty()) {
                if (not(visited[s.top()])) {
                        scc_size.pb(0);
                        dfs2(s.top());
                        ans=max(ans, scc_size[scc_size.size()-1]);
                }
                s.pop();
        }
        cout << ans << "\n";


        return 0;
}

