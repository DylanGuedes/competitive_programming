#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
#define pb push_back
using ll = long long;
#define all(x) x.begin(),x.end()

#define MAX 200020
int pleas[MAX];
vector<int> graph[MAX];
ll sum_all[MAX];
ll best_tree[MAX];
set<ll> myset;
ll ans;

void dfs(int idx, int parent)
{
        sum_all[idx]=pleas[idx];
        best_tree[idx]=-((ll)1<<60);
        for (auto it : graph[idx]) {
                if (it==parent)
                        continue;
                else {
                        dfs(it, idx);
                        sum_all[idx]+=sum_all[it];
                        best_tree[idx]=max(best_tree[it], best_tree[idx]);
                }
        }
        best_tree[idx]=max(best_tree[idx], sum_all[idx]);
}

void dfs2(int idx, int parent)
{
        int child=0;
        for (auto it : graph[idx]) {
                if (it==parent)
                        continue;
                else {
                        dfs2(it, idx);
                        child++;
                }
        }

        if (child>=2) {
                vector<ll> possible;
                for (auto it : graph[idx]) {
                        if (it==parent)
                                continue;
                        possible.pb(best_tree[it]);
                }
                sort(all(possible), greater<ll>());
                ans=max(ans, possible[0]+possible[1]);
        }
}

int main()
{
        ios::sync_with_stdio(false);
        int n, origin, destination;
        cin >> n;
        rep(i, 0, n) {
                cin >> pleas[i];
        }
        rep(i, 0, n-1) {
                cin >> origin >> destination;
                graph[origin-1].pb(destination-1);
                graph[destination-1].pb(origin-1);
        }
        memset(sum_all, 0, sizeof sum_all);
        dfs(0, -1);
        ans=-(ll)1<<60;
        dfs2(0, -1);
        if (ans==-(ll)1<<60) {
                cout << "Impossible\n";
        } else {
                cout << ans << "\n";
        }
        return 0;
}
