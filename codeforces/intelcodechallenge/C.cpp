#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
#define repd(i, j, k)for(int i=k;i>=j;i--)
#define pb(i) push_back(i)
#define eb(i, j) emplace_back(i, j)
using ll = long long;
using ii = pair<int, int>;
int n;
int arr[100100];
int p[100100];
int parent[100100];
int tot_set[100100];

int union_find(int x)
{
        if (parent[x] == x)
                return x;
        else
                return union_find(parent[x]);
}

void make_union(int x, int y)
{
        int rootx = union_find(x);
        int rooty = union_find(y);
        tot_set[rootx]+=tot_set[rooty];
        parent[rooty]=rootx;
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;

        repi(i, 0, n)
                cin >> arr[i];

        repi(i, 0, n) {
                cin >> p[i];
                p[i]-=1;
                parent[i] = i;
        }

        memset(tot_set, 0, sizeof tot_set);

        int sum = 0;
        repd(i, 0, n-1) {
                tot_set[p[i]] = arr[p[i]];

                if (i>0) {
                        make_union(p[i], p[i-1]);
                        sum = max(sum, tot_set[union_find(p[i])]);
                }

                if (i<n-1) {
                        make_union(p[i], p[i+1]);
                        sum = max(sum, tot_set[union_find(p[i])]);
                }

                cout << sum << "\n";
        }
        return 0;
}
