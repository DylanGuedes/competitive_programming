#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
#define repd(i, j, k)for(int i=j;i>k;i--)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
using ii = pair<int, int>;

int c[200005];
int m;
set<int> myset;
vector<int> graph[200005];
int visited[200005];
map<int, int> mymap;
vector<int> myv;
int highest = -1<<30;
int correct_idx = -1;

void dfs(int idx)
{
        visited[idx]=1;

        if (mymap.find(c[idx]) != mymap.end()) {
                mymap[c[idx]]++;
        } else {
                mymap.emplace(c[idx], 1);
        }

        if (highest < mymap[c[idx]]) {
                correct_idx = c[idx];
                highest = mymap[c[idx]];
        }

        for (auto it : graph[idx]) {
                if (not visited[it])
                        dfs(it);
        }
}

int main()
{
        ios::sync_with_stdio(false);
        int n, k;
        int origin, destination;
        cin >> n >>  m >> k;
        repi(i, 0, n) {
                cin >> c[i];
                c[i]--;
        }

        repi(i, 0, m) {
                cin >> origin >> destination;
                graph[origin-1].pb(destination-1);
                graph[destination-1].pb(origin-1);
        }

        memset(visited, 0, sizeof visited);

        int total = 0;
        repi(i, 0, n) {
                mymap.clear();
                highest = -1<<30;

                if (visited[i])
                        continue;

                dfs(i);

                int len = myv.size();

                for (auto it : mymap) {
                        if (it.first == correct_idx)
                                continue;
                        total+=it.second;
                }
        }

        cout << total<< "\n";
        return 0;
}
