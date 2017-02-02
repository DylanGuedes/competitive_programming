#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
#define rep(i, j, k)for(int i=j;i<k;++i)
#define eb emplace_back
#define pb push_back
vector<ii> graph[100011];
int val[100011];
int dp[100011];

void dfs(int idx, int parent)
{
        int to, comm;
        for (auto it : graph[idx]) {
                tie(comm, to)=it;
                if (to==parent)
                        continue;
                dp[idx]+=val[idx];
                dfs(to, idx);
                dp[idx]+=dp[to];
        }
}

int main()
{
        ios::sync_with_stdio(false);
        int n;
        cin >> n;
        int origin, destination, comm;
        memset(val, 0, sizeof val);
        memset(dp, 0, sizeof dp);
        rep(i,0, n-1) {
                cin >> origin >> destination >> comm;
                graph[destination-1].eb(comm, origin-1);
                graph[origin-1].eb(comm, destination-1);
                val[origin-1]=max(0, (int)(comm==2));
                val[destination-1]=max(0, (int)(comm==2));
        }
        dfs(0, 0);
        vector<int> ans;
        rep(i, 0, n) {
                if (val[i]==1)
                        ans.pb(i+1);
        }

        cout << ans.size() << "\n";
        for (auto it : ans) {
                cout << it << " ";
        }
        cout << "\n";


        return 0;
}
