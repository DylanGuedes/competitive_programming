#include <iostream>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

using ll = long long;
using ii = pair<ll, ll>;
ll arr[3];

int main()
{
        ll x, y;
        cin >> x >> y;
        FOR(i, 0, 3) {
                arr[i] = y;
        }

        int moves = 0;
        while (arr[0]!=x || arr[1]!=x || arr[2]!=x) {
                // printf("[%d, %d, %d]\n", arr[0], arr[1], arr[2]);
                ii best(10000000, -1);
                FOR(i, 0, 3) {
                        if (arr[i] < best.first) {
                                best.first = arr[i];
                                best.second = i;
                        }
                }
                ll sum = 0;
                FOR(i, 0, 3) {
                        if (i == best.second)
                                continue;
                        sum += arr[i];
                }
                sum -= 1;
                arr[best.second] = min(sum, x);
                ++moves;
        }
        cout << moves << "\n";
        return 0;
}
