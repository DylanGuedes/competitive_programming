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

#define MAX 2005
int n;
string str;
int parent[MAX];
vector<int> graph[MAX];
set<int> myset;

void dfs(int idx, int group, int parent)
{
        myset.ins(group);
        for (auto it : graph[idx]) {
                if (it==parent)
                        continue;
                dfs(it, group+1, idx);
        }
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;
        int aux;
        rep(i, 0, n) {
                cin >> aux;
                if (aux==-1)
                        parent[i]=-1;
                else {
                        graph[aux-1].pb(i);
                        graph[i].pb(aux-1);
                }
        }
        rep(i, 0, n) {
                if (parent[i]==-1) {
                        dfs(i, 1, -1);
                }
        }
        cout << myset.size() << "\n";
        return 0;
}
