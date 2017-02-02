#include <iostream>
#include <vector>

using namespace std;

struct row {
        char s1, s2, s3, s4;
};
int n;

vector<row> rows;

int main()
{
        ios::sync_with_stdio(false);
        char buf;
        cin >> n;
        row r;
        for (int i=0; i < n; ++i) {
                cin >> r.s1 >> r.s2 >> buf >> r.s3 >> r.s4;
                rows.push_back(r);
        }
        bool yes = false;
        for (int i=0; i < n; ++i) {
                if (rows[i].s1 == 'O' && rows[i].s2 == 'O') {
                        rows[i].s1 = '+';
                        rows[i].s2 = '+';
                        yes = true;
                        break;
                } else if (rows[i].s3 == 'O' && rows[i].s4 == 'O') {
                        rows[i].s3 = '+';
                        rows[i].s4 = '+';
                        yes = true;
                        break;
                }
        }
        if (yes) {
                cout << "YES" << "\n";
                for (auto it : rows) {
                        cout << it.s1 << it.s2 << buf << it.s3 << it.s4 << "\n";
                }
        } else {
                cout << "NO" << "\n";

        }
        return 0;
}
