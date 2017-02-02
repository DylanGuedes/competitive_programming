#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
#define all(x) x.begin(), x.end()
using ll = long long;
using ii = pair<int, int>;
#define repd(i, j, k)for(int i=j;i>=k;i--)
#define pb push_back
#define eb emplace_back
#define emp emplace
#define ins insert
#define mp make_pair
double const eps = 1e-10;
double const pi = acos(-1);

int visited[200005];
int ranks[200005];
int color[200005];
int parent[200005];

vector<int> graph[200005];
vector<int> g2[200005];

int union_find(int x)
{
        if (x==parent[x])
                return x;
        else
                return parent[x]=union_find(parent[x]);
}

void make_union(int x, int y)
{
        int rootx=union_find(x);
        int rooty=union_find(y);
        if (ranks[rootx]>=ranks[rooty]) {
                ranks[rootx]++;
                parent[rooty]=rootx;
        } else {
                ranks[rooty]+=1;
                parent[rootx]=rooty;
        }
}

void dfs2(int idx)
{
        visited[idx]=1;
        for (auto it:graph[idx]) {
                if (visited[it])
                        continue;
                if (color[it]!=color[idx]) {
                        g2[union_find(idx)].pb(union_find(it));
                        g2[union_find(it)].pb(union_find(idx));
                        continue;
                }
                dfs2(it);
        }
}

void dfs1(int idx)
{
        visited[idx]=1;
        for (auto it : graph[idx]) {
                if (visited[it])
                        continue;
                if (color[it]!=color[idx]) {
                        g2[union_find(idx)].pb(union_find(it));
                        g2[union_find(it)].pb(union_find(idx));
                        continue;
                }
                make_union(idx, it);
                dfs1(it);
        }
}

int bfs(int idx)
{
        queue<int> q1;
        q1.emplace(idx);
        memset(visited, 0, sizeof visited);
        visited[idx]=1;
        while (not q1.empty()) {
                idx=q1.front(); q1.pop();
                for (auto it:g2[idx]) {
                        if (!visited[it]) {
                                visited[it]=1;
                                q1.emplace(union_find(it));
                        }
                }
        }
        queue<ii> q2;
        q2.emplace(0, idx);
        memset(visited, 0, sizeof visited);
        int val=0;
        visited[idx]=1;
        while (not q2.empty()) {
                val=max(val, q2.front().first);
                idx=q2.front().second;
                q2.pop();
                for (auto it:g2[idx]) {
                        if (!visited[it]) {
                                visited[it]=1;
                                q2.emplace(val+1, union_find(it));
                        }
                }
        }
        return val;
}

int main()
{
        ios::sync_with_stdio(false);

        int n;
        cin >> n;

        int origin, destination;
        rep(i, 0, n) {
                cin >> color[i];
        }

        rep(i, 0, n-1) {
                cin >> origin >> destination;
                graph[origin-1].pb(destination-1);
                graph[destination-1].pb(origin-1);
        }


        rep(i, 0, n+2) {
                parent[i]=i;
        }

        memset(ranks, 0, sizeof ranks);
        memset(visited, 0, sizeof visited);
        rep(i, 0, n) {
                if (!visited[i]) {
                        dfs1(i);
                }
        }
        memset(visited, 0, sizeof visited);
        rep(i, 0, n) {
                if (!visited[union_find(i)]) {
                        dfs2(union_find(i));
                }
        }

        set<int> myset;
        rep(i, 0, n) {
                myset.insert(union_find(i));
        }

        // cout << "G2:\n";
        // for (auto it : myset) {
        //         cout << it+1 << "=>\n";
        //         for (auto &x:g2[it]) {
        //                 x=union_find(x);
        //                 cout << "\t"<<x+1<<"\n";
        //         }
        // }
        cout << (bfs(*myset.begin())+1)/2 << "\n";

        return 0;
}
