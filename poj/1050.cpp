#include <iostream>
#include <cstring>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int arr[110][110];

int main()
{
        ios::sync_with_stdio(false);
        int n;
        cin >> n;
        FOR(i, 0, n) {
                FOR(j, 0, n) {
                        cin >> arr[i][j];
                        if (i > 0) arr[i][j] += arr[i-1][j];
                        if (j > 0) arr[i][j] += arr[i][j-1];
                        if (i > 0 && j > 0) arr[i][j] -= arr[i-1][j-1];
                }
        }

        long long max2d = -1<<30;

        long long rect = 0;
        FOR(i, 0, n) {
                FOR(j, 0, n) {
                        FOR(k, i, n) {
                                FOR(l, j, n) {
                                        rect = arr[k][l];
                                        if (i > 0) rect -= arr[i-1][l];
                                        if (j > 0) rect -= arr[k][j-1];
                                        if (i > 0 && j > 0) rect += arr[i-1][j-1];
                                        max2d = max(max2d, rect);
                                }
                        }
                }
        }
        cout << max2d << "\n";
        return 0;
}
