#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)

char grid[10][10];

using ii = pair<int, int>;

int main()
{
        ios::sync_with_stdio(false);
        rep(i, 0, 8) {
                rep(j, 0, 8) {
                        cin >> grid[i][j];
                }
        }

        bool possible = true;

        rep(i, 0, 8) {
                rep(j, 0, 8) {
                        vector<int> myv { j+1, j-1 };
                        for (auto it : myv) {
                                if (it<0 || it==8)
                                        continue;
                                if (grid[i][j] == grid[i][it])
                                        possible = false;
                        }
                }
        }
        if (possible)
                cout << "YES\n";
        else
                cout << "NO\n";
        return 0;
}
