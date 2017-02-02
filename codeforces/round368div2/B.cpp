#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

struct edge {
    int x, y, z;
};

set<int> storages;
vector<edge> edges;
int parent[100005];
int ranks[100005];

bool myfunc(edge e1, edge e2)
{
    return e1.z < e2.z;
}

int union_find(int x)
{
    if (x == parent[x])
        return x;
    else
        return parent[x] = union_find(parent[x]);
}

void make_union(int x, int y)
{
    int rootx = union_find(x);
    int rooty = union_find(y);
    if (ranks[rootx] >= ranks[rooty]) {
        ranks[rootx]++;
        parent[rooty] = rootx;
    } else {
        ranks[rooty]++;
        parent[rootx] = rooty;
    }
}

bool myfunc2(edge e1, edge e2)
{
    return e1.z < e2.z;
}

int main()
{
    int n, m, k, city;
    cin >> n >> m >> k;
    edge e;
    FOR(i, 0, m) {
        scanf("%d%d%d", &e.x, &e.y, &e.z);
        edges.push_back(e);
    }
    FOR(i, 0, k) {
        cin >> city;
        storages.insert(city);
    }
    memset(ranks, 0, sizeof ranks);
    FOR(i, 0, n+2)
        parent[i] = i;
    sort(edges.begin(), edges.end(), myfunc);
    int edges_size = edges.size();
    vector<edge> mst;
    FOR(i, 0, edges_size) {
        if (union_find(edges[i].x) != union_find(edges[i].y)) {
            make_union(edges[i].x, edges[i].y);
            mst.push_back(edges[i]);
        }
    }

    // sort(mst.begin(), mst.end(), myfunc2);
    int mst_size = mst.size();
    int resp = -1;
    FOR(i, 0, mst_size) {
        if ((storages.count(mst[i].x) > 0 && storages.count(mst[i].y) == 0) || (storages.count(mst[i].y) > 0 && storages.count(mst[i].x) == 0)) {
            resp = i;
            break;
        }
    }
    if (resp != -1)
        cout << mst[resp].z << "\n";
    else
        cout << "-1" << "\n";

    return 0;
}
