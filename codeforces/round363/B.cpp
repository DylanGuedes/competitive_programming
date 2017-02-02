#include <iostream>
#include <cstring>

using namespace std;

string grid[1010];

#define FOR(i, j, k)for(int i=j;i<k;++i)

int main()
{
    int n, m;
    int rows[1010];
    int cols[1010];
    memset(rows, 0, sizeof rows);
    memset(cols, 0, sizeof cols);
    int total = 0;

    cin >> n >> m;
    FOR(i, 0, n) {
        cin >> grid[i];
    }

    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if (grid[i][j] == '*') {
                rows[i]++;
                cols[j]++;
                total++;
            }
        }
    }

    bool possible = false;
    pair<int, int> ans;
    FOR(i, 0, n)
    {
        FOR(j, 0, m) {
            int cnt = 0;
            cnt += cols[j] + rows[i];
            if (grid[i][j] == '*') {
                cnt -= 1;
            }
            if (cnt == total) {
                possible = true;
                ans.first = j;
                ans.second = i;
                break;
            }
        }
    }

    if (possible) {
        printf("YES\n");
        printf("%d %d\n", ans.second+1, ans.first+1);
    } else {
        printf("NO\n");
    }

    return 0;
}
