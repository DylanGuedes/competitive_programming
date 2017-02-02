#include <iostream>

using namespace std;

using ll = long long;

int main()
{
        ll l1, r1, l2, r2, k;
        ios::sync_with_stdio(false);
        cin >> l1 >> r1 >> l2 >> r2 >> k;
        ll l_m = max(l1, l2);
        ll r_m = min(r1, r2);
        if (r_m < l_m)
                cout << "0\n";
        else {
                if (k >= l_m && k <= r_m)
                        cout << r_m-l_m << "\n";
                else
                        cout << r_m-l_m+1 << "\n";
        }
        return 0;
}
