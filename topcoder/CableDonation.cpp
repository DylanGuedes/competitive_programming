#include <vector>
#include <cstring>

int ranks[51];
int parent[51];

struct edge {
        int x, y, z;
};

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

vector<edge> edges;
class CableDonation {
public:
        int cable(vector <string> lengths)
        {
                edges.clear();
                int n = lengths.size();
                for (int i=0; i < n; ++i) {
                        for (int j=0; j < n; ++j) {
                                if (lengths[i][j] == '0') continue;
                                if (islower(lengths[i][j])) {
                                        e.x = i;
                                        e.y = j;
                                        e.z = lengths[i][j] - 'a' + 1;
                                } else {
                                        e.x = i;
                                        e.y = j;
                                        e.z = lengths[i][j] - 'A' + 1;
                                }
                                edges.push_back(e);
                        }
                }

                sort(edges.begin(), edges.end(), myfunc);
                FOR(i, 0, n+2) {
                        parent[i] = i;
                }
                memset(ranks, 0, sizeof ranks);

                long long total = 0;
                int edges_size = edges.size();
                FOR(i, 0, edges_size) {
                        if (union_find(edges[i].x) != union_find(edges[i].y)) {
                                make_union(edges[i].x, edges[i].y);
                        } else {
                                total += edges[i].z;
                        }
                }
                cout << total << "\n";
        }
};
