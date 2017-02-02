#include <iostream>
#include <set>

using namespace std;

char grid[101][101];

#define FOR(i, j, k)for(int i=j;i<k;++i)

int main()
{
    int n, m;
    cin >> n >> m;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cin >> grid[i][j];
        }
    }

    set<char> s;
    s.insert('C');
    s.insert('M');
    s.insert('Y');
    bool possible = true;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if (s.count(grid[i][j]) > 0) {
                possible = false;
                break;
            }
        }
        if (not possible)
            break;
    }

    if (not possible)
        cout << "#Color" << "\n";
    else
        cout << "#Black&White" << "\n";

    return 0;
}
