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
int color[200005];

vector<int> graph[200005];

int bfs(int idx)
{
        queue<ii> q1;
        q1.emplace(0, idx);
        memset(visited, 0, sizeof visited);
        visited[idx]=1;
        int val=0;
        int that=-1;
        int maislonge=-1<<30;
        while (not q1.empty()) {
                tie(val, idx)=q1.front();
                if (val>maislonge) {
                        maislonge=val;
                        that=idx;
                }
                q1.pop();
                for (auto it:graph[idx]) {
                        if (!visited[it]) {
                                visited[it]=1;
                                int aggr= color[it]!=color[idx] ? 1 : 0;
                                q1.emplace(val+aggr, it);
                        }
                }
        }



        idx=that;


        queue<ii> q2;
        q2.emplace(0, idx);
        val=0;
        memset(visited, 0, sizeof visited);
        visited[idx]=1;
        int aggr;
        int ans=-1<<30;
        while (not q2.empty()) {
                tie(val, idx)=q2.front();
                ans=max(ans, val);
                q2.pop();
                for (auto it:graph[idx]) {
                        if (!visited[it]) {
                                aggr = color[it]!=color[idx] ? 1 : 0;
                                visited[it]=1;
                                q2.emplace(val+aggr, it);
                        }
                }
        }
        return ans;
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

        cout << (bfs(0)+1)/2 << "\n";

        return 0;
}
