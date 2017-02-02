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
#define debug(x) cout << #x << " = " << x << endl

#define MAX 10005
int n, m;
int parent[MAX];
int ranks[MAX];
string str;

int union_find(int x)
{
        if (x == parent[x]) {
                return x;
        } else {
                return parent[x] = union_find(parent[x]);
        }
}

void make_union(int x, int y)
{
        int rootx = union_find(x);
        int rooty = union_find(y);
        if (ranks[rootx]>=ranks[rooty]) {
                ranks[rootx]++;
                parent[rooty]=rootx;
        } else {
                ranks[rooty]++;
                parent[rootx]=rooty;
        }
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;
        int aux;
        memset(ranks, 0, sizeof ranks);
        rep(i, 0, n+5) {
                parent[i]=i;
        }
        rep(i, 0, n) {
                cin >> aux;
                aux-=1;
                make_union(i, aux);
        }

        set<int> conj;
        rep(i, 0, n) {
                conj.insert(union_find(i));
        }
        cout << conj.size() << "\n";

        return 0;
}
