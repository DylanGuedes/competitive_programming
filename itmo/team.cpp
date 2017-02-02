#include <bits/stdc++.h>
#ifdef JUDGE
std::ifstream fin("team.in");
std::ofstream fout("team.out");
#else
#define fin cin
#define fout cout
#endif

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)

using ll = long long;

int grid[4][4];

int main() {
        rep(i, 0, 3) {
                rep(j, 0, 3) {
                        fin >> grid[i][j];
                }
        }

        double ans = -100000.0;
        rep(i, 0, 3) {
                rep(j, 0, 3) {
                        rep(k, 0, 3) {
                                if (i==j || i==k || j==k)
                                        continue;

                                ans = max(ans, sqrt(grid[0][i]*grid[0][i] + grid[1][j]*grid[1][j] + grid[2][k]*grid[2][k]));

                        }
                }
        }

        fout << fixed << ans << "\n";
        return 0;
}
