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

int n, k;
string str;

#define MAX 100010
int state[MAX];
vector<int> graph[MAX];

bool impossible;
int visited[MAX];
int dfs(int idx)
{
        visited[idx]=1;
        int total=0;
        for (auto it : graph[idx]) {
                if (visited[it]) {
                        if (state[it]==state[idx]) {
                                impossible=true;
                                return 1<<30;
                        }
                        continue;
                }
                if (state[it]==state[idx]) {
                        state[it]=1-state[it];
                        total++;
                }
                total+=dfs(it);
        }
        return total;
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;
        char col;
        rep(i, 0, n) {
                cin >> col;
                col == 'B' ? state[i]=1 : state[i]=0;
        }
        int origin, destination;
        rep(i, 0, n-1) {
                cin >> origin >> destination;
                graph[origin-1].pb(destination-1);
                graph[destination-1].pb(origin-1);
        }
        memset(visited, 0, sizeof visited);
        impossible=false;

        int total=dfs(0);

        if (impossible) {
                cout << -1 << "\n";
        } else {
                cout << total << "\n";
        }
        return 0;
}
