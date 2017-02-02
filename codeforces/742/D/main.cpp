#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
#define repd(i, j, k)for(int i=j;i>=k;i--)
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define ins insert
#define popb pop_back
using ii = pair<int, int>;
using ll = long long;
map<int, ii > dict;
int n;
int m;
int w;
int beauty[1010];
int wei[1010];
int parent[1010];
int ranks[1010];
vector<ii> myv;
int dp[1010][1010];

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
        if (ranks[rootx]>=ranks[rooty]) {
                ranks[rootx]+=1;
                parent[rooty]=rootx;
        } else {
                ranks[rooty]+=1;
                parent[rootx]=rooty;
        }
}

int solve(int idx, int remaining)
{
        cout << "solve("<<idx<<","<<remaining<<")\n";
        if (idx == myv.size()) {
                return 0;
        }

        if (remaining<0)
                return 0;

        if (dp[idx][remaining]!=-1)
                return dp[idx][remaining];

        int ans = solve(idx+1, remaining);
        cout << "ans1: " << ans << "\n";

        if (remaining>=myv[idx].second) {
                ans = max(ans, solve(idx+1, remaining-myv[idx].second)+myv[idx].first);
                cout << "ans2: " << ans << "\n";
        }

        return dp[idx][remaining]=ans;
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> m >> w;
        rep(i, 0, n+2) {
                parent[i]=i;
                ranks[i]=0;
        }
        rep(i, 0, n) {
                cin >> wei[i];
                }
        rep(i, 0, n) {
                cin >> beauty[i];
        }

        int origin, destination;
        rep(i, 0, m) {
                cin >> origin >> destination;
                make_union(origin-1, destination-1);
        }

        rep(i, 0, n) {
                if (dict.find(union_find(i)) == dict.end()) {
                        dict.emplace(union_find(i), ii(beauty[i], wei[i]));
                } else {
                        dict[union_find(i)].first+=beauty[i];
                        dict[union_find(i)].second+=wei[i];
                }
        }

        for (auto it : dict) {
                myv.eb(it.second.first, it.second.second);
        }

        cout << "MYV:\n";
        for (auto it : dict) {
                cout << it.second.first << " " << it.second.second << "\n";
        }

        memset(dp, -1, sizeof dp);
        cout << solve(0, w) << "\n";

        return 0;
}

