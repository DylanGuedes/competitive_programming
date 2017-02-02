#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)

struct place {
        int x, y;
};

place tel[1010];
place mons[1010];
int k, n;

int main()
{
        ios::sync_with_stdio(false);
        cin >> k >> n;

        repi(i, 0, k)
                cin >> tel[i].x >> tel[i].y;

        repi(i, 0, n)
                cin >> mons[i].x >> mons[i].y;

        cout << solve(0

        return 0;
}
