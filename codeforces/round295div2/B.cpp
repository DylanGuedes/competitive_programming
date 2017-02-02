#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
using ii = pair<int, int>;
#define pb(i) push_back(i)
#define eb(i, j) emplace_back(i, j)

int visited[10050];
int n, m;

void bfs(int origin, int destination)
{
        queue<ii> q;
        q.emplace(0, origin);
        visited[origin] = 1;

        int resp = 1<<30;
        while (not q.empty()) {
                int val, idx;
                tie(val, idx) = q.front();
                q.pop();
                vector<int> myv {idx*2, idx-1};
                if (idx == destination) {
                        resp = val;
                        break;
                }

                for (auto it : myv) {
                        if (it < 1)
                                continue;
                        if (it>10000)
                                continue;
                        if (visited[it]) {
                                continue;
                        }
                        visited[it] = 1;
                        q.emplace(val+1, it);
                }
        }
        cout << resp << "\n";
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> m;

        memset(visited, 0, sizeof visited);
        bfs(n, m);
        return 0;
}
