#include <bits/stdc++.h>

using namespace std;

const int MYMOD = 1000000007;
multiset<int> appear;
int arr[100010];
int visited[100010];
int n, m, origin, destination;
vector<int> graph[100010];
vector<int> rev[100010];
stack<int> s;
int mymin;
using ll = long long;
using ii = pair<int, int>;
#define rep(i, j, k)for(int i=j;i<k;++i)
#define pb push_back
int elements;

void dfs(int idx)
{
        visited[idx]=1;
        for (auto it : graph[idx]) {
                if (visited[it])
                        continue;
                dfs(it);
        }
        s.push(idx);
}

void dfs2(int idx)
{
        visited[idx]=1;
        if (arr[idx]==mymin) {
                elements++;
        }
        if (arr[idx]<mymin) {
                elements=1;
                mymin=arr[idx];
        }
        appear.insert(arr[idx]);
        for (auto it : rev[idx]) {
                if (visited[it])
                        continue;
                dfs2(it);
        }
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;
        rep(i, 0, n) {
                cin >> arr[i];
        }
        cin >> m;
        rep(i, 0, m) {
                cin >> origin >> destination;
                graph[origin-1].pb(destination-1);
                rev[destination-1].pb(origin-1);
        }

        memset(visited, 0, sizeof visited);
        rep(i, 0, n) {
                if (!visited[i])
                        dfs(i);
        }

        memset(visited, 0, sizeof visited);
        ll result=1;
        vector<ii> scc;
        while (not s.empty()) {
                if (not(visited[s.top()])) {
                        appear.clear();
                        elements=0;
                        mymin=1<<30;
                        dfs2(s.top());
                        scc.pb(ii(mymin, s.top()));
                        result=(result*(ll)elements)%MYMOD;
                }
                s.pop();
        }
        ll total=0;
        for (auto it : scc) {
                total+=it.first;
        }
        cout << total << " " << (result%MYMOD) << "\n";

        return 0;
}
