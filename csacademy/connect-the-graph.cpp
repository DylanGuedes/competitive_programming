#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define emp emplace
#define ins insert
#define rep(i, j, k)for(int i=j;i<k;++i)
#define DEBUG(arg, x) cout << arg << " => " << x << "\n"

using ii = pair<int, int>;
using ll = long long;
int n, m;
int parent[100010];
int ranks[100010];

struct edge {
        int x, y;
};

vector<edge> edges;
vector<edge> can_delete;

int union_find(int x)
{
        if (x==parent[x])
                return x;
        else
                return parent[x]=union_find(parent[x]);
}

void make_union(int x, int y)
{
        x=union_find(x);
        y=union_find(y);
        if (ranks[x]>=ranks[y]) {
                ranks[x]++;
                parent[y]=x;
        } else {
                ranks[y]++;
                parent[x]=y;
        }
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> m;
        edge e;
        rep(i, 0, m) {
                cin >> e.x >> e.y;
                e.x-=1;
                e.y-=1;
                edges.pb(e);
        }

        int unions=0;
        rep(i, 0, n+2)
                parent[i]=i;
        memset(ranks, 0, sizeof ranks);

        rep(i, 0, m) {
                if (union_find(edges[i].x)!=union_find(edges[i].y)) {
                        make_union(edges[i].x, edges[i].y);
                        unions++;
                } else {
                        can_delete.pb(edges[i]);
                }
        }

        vector<edge> added;
        int deleted=0;
        rep(i, 0, n) {
                rep(j, i+1, n) {
                        if (unions==n-1) {
                                i=1<<30;
                                break;
                        }
                        int x=union_find(i);
                        int y=union_find(j);
                        if (parent[x]!=parent[y]) {
                                unions++;
                                e.x=x;
                                e.y=y;
                                make_union(x, y);
                                added.pb(e);
                                deleted++;
                        }
                }
        }

        if (deleted<=can_delete.size()) {
                cout << deleted <<"\n";
                rep(i, 0, deleted) {
                        cout << can_delete[i].x+1 << " " << can_delete[i].y+1 << " " << added[i].x+1 << " " << added[i].y+1 << "\n";
                }
        } else {
                cout << -1 << "\n";
        }
        return 0;
}
