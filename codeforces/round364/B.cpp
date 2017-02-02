#include <iostream>
#include <set>

using namespace std;

#define ii pair<long int,long int>

set<ii> grid;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int main()
{
    long long int n, m, xi, yi;
    cin >> n >> m;
    FOR(i, 0, m) {
        cin >> xi >> yi;
        if (i != 0)
            printf(" ");
        xi -= 1;
        yi -= 1;

        FOR(j, 0, n) {
            grid.insert(make_pair(xi, j));
            grid.insert(make_pair(j, yi));
        }

        long long int total = grid.size();
        cout << (n*n - total);
    }
    printf("\n");
    return 0;
}
