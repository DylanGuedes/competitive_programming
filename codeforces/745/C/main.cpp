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

int n, m, k;
bool govern[1020];
int parent[1020];
int ranks[1020];
int origin, destination;

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
        if (govern[x]==true) {
                parent[rooty]=rootx;
                ranks[rootx]++;
        } else if (govern[y]==true) {
                parent[rootx]=rooty;
                ranks[rooty]++;
        } else {
                if (ranks[rootx]>=ranks[rooty]) {
                        ranks[rootx]+=ranks[rooty]+1;
                        parent[rooty]=rootx;
                } else {
                        ranks[rooty]+=ranks[rootx]+1;
                        parent[rootx]=rooty;
                }
        }
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> m >> k;
        memset(govern, 0, sizeof govern);
        int aux;

        memset(ranks, 0, sizeof ranks);
        rep(i, 0, k) {
                cin >> aux;
                aux-=1;
                govern[aux]=true;
        }

        rep(i, 0, n+2) {
                parent[i]=i;
        }

        int best_set=0;
        int best_set_idx=0;
        rep(i, 0, m) {
                cin >> origin >> destination;
                make_union(origin-1, destination-1);
                if (ranks[union_find(origin-1)]>best_set && govern[union_find(origin-1)]) {
                        best_set=ranks[union_find(origin-1)];
                        best_set_idx=union_find(origin-1);
                }
        }

        map<int, ii> mymap;
        rep(i, 0, n) {
                if (union_find(i)==union_find(best_set_idx))
                        continue;
                if (mymap.find(union_find(i))!=mymap.end())
                        continue;
                int ele=0;
                rep(j, 0, n) {
                        if (union_find(i)==union_find(j)) {
                                ele++;
                        }
                }
                mymap.emplace(union_find(i), mp(ranks[union_find(i)], ele));
        }

        int atm=best_set;

        int elements=0;
        rep(i, 0, n) {
                if (govern[union_find(i)]==false) {
                }
        }
        rep(i, 0, n) {
                if (parent[i]!=i && govern[union_find(i)]==false) {
                        make_union(i, best_set_idx);
                        continue;
                }
                if (govern[i]==false && (parent[i]==i) || govern[union_find(i)]==false) {
                        make_union(i, best_set_idx);
                }
        }
        rep(i, 0, n) {
                if (union_find(i)==union_find(best_set_idx)) {
                        elements++;
                }
        }

        cout << "atm: " << atm << "\n";
        n=(elements*(elements-1));
        n/=2;
        ll total=n-atm;
        for (auto it : mymap) {
                int edgs, nodes;
                tie(edgs, nodes)=it.second;
                total+=(nodes*(nodes-1)/2)-edgs;
        }
        cout << total << "\n";

        return 0;
}
