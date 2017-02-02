#include <bits/stdc++.h>

using namespace std;

int h, w;
#define repi(i, j, k)for(int i=j;i<k;++i)

#define eb(e1, e2) emplace_back(e1, e2);
#define x first
#define y second
using ii = pair<int, int>;

char grid[14][14];
int visited[14][14];

void bfs(int _x, int _y)
{
        queue< pair<int, ii> > myq;
        myq.emplace(0, ii(_x, _y));
        ii node(0, 0);

        while (not myq.empty()) {
                auto idx = myq.front().second;
                int val = myq.front().first;
                node = idx;
                myq.pop();
                visited[idx.y][idx.x] = 1;


                vector<ii> myv {ii(idx.x, idx.y+1), ii(idx.x, idx.y-1), ii(idx.x+1, idx.y), ii(idx.x-1, idx.y) };
                for (auto it : myv) {
                        if (it.x < 0 || it.second < 0 || it.x >= w || it.y >= h)
                                continue;
                        if (visited[it.y][it.x])
                                continue;
                        if (grid[it.y][it.x] != '.')
                                continue;
                        myq.emplace(val+1, ii(it.x, it.y));
                }
        }
}

int main()
{
        ios::sync_with_stdio(false);
        int t;
        cin >> t;
        while(t--) {
                cin >> h >> w;
                vector<ii> myv;
                repi(i, 0, h) {
                        repi(j, 0, w) {
                                cin >> grid[i][j];
                                if (grid[i][j] == 'D') {
                                        myv.eb(j, i);
                                }
                        }
                }

                memset(visited, 0, sizeof visited);
                for (auto door : myv) {
                        bfs(door.x, door.y);
                }
        }
        return 0;
}
