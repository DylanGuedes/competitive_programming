#include <iostream>
#include <vector>
#include <queue>

#define FOR(i, j, k)for(int i=j;i<k;++i)

using namespace std;

using ii = pair<int, int>;

int col[200005];
vector<int> graph[200005];
int visited[200005][3];
int n;

int inv(int idx)
{
        if (idx == 1)
                return -1;
        else
                return 1;
}

void bfs()
{
        queue< pair<ii, vector<int> > > q;
        q.push(make_pair(make_pair(0, 0), vector<int>()));
        int lastval;
        vector<int> ans;
        while (not q.empty()) {
                int idx = q.front().first.second;
                int val = q.front().first.first;
                q.front().second.push_back(idx);
                vector<int> myq = q.front().second;
                ans = myq;

                col[idx] = inv(col[idx]);
                q.pop();
                lastval = val;

                for (auto it : graph[idx]) {
                        if (not visited[it][col[it]+1]) {
                                visited[it][col[it]+1] = 1;
                                q.push(make_pair(make_pair(val+1, it), myq));
                        }
                }
        }
        cout << lastval << "\n";
        cout << "path: " << "\n";
        for (auto it : ans) {
                cout << it+1 << " ";
        }
        cout << "\n";
}


int main()
{
        int origin, destination;
        scanf("%d", &n);
        FOR(i, 0, n) {
                scanf("%d", &col[i]);
        }
        FOR(i, 0, n-1) {
                scanf("%d%d", &origin, &destination);
                graph[origin-1].push_back(destination-1);
                graph[destination-1].push_back(origin-1);
        }
        bfs();

        return 0;
}
