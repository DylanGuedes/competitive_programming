#include <iostream>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

using ll = long long;

ll a[505][505];

int main()
{
        ios::sync_with_stdio(false);
        int n;
        int row_no_zero = -1, row_zero = -1;
        cin >> n;
        if (n == 1) {
                cin >> a[0][0];
                cout << "1\n";
                return 0;
        }

        ll part_sum;
        ll row_sum;
        bool impossible = false;

        FOR(i, 0, n) {
                bool no_zero = true;

                ll idx_sum = 0;

                FOR(j, 0, n) {
                        cin >> a[i][j];
                        if (not a[i][j])
                                no_zero = false;

                        idx_sum += a[i][j];
                }

                if (no_zero) {
                        if (row_no_zero != -1) {
                                if (idx_sum != row_sum) {
                                        impossible = true;
                                }
                        } else {
                                row_no_zero = i;
                                row_sum = idx_sum;
                        }
                } else {
                        row_zero = i;
                }
        }

        if (not impossible) {
                int k = 0;
                ll total_1 = 0;
                FOR(i, 0, n) {
                        if (a[row_zero][i] == 0)
                                k++;
                        total_1 += a[row_zero][i];
                }
                ll total = 0;
                FOR(i, 0, n) {
                        total += a[row_no_zero][i];
                }
                ll ans = (total - total_1)/k;
                if (ans)
                        cout << ans << "\n";
                else
                        cout << "-1" << "\n";
        } else {
                cout << "-1" << "\n";
        }

        return 0;
}
