#include <bits/stdc++.h>

using namespace std;

int main()
{
        ios::sync_with_stdio(false);
        int w;
        cin >> w;
        if (w&1)
                cout << "NO\n";
        else {
                if (w == 2)
                        cout << "NO\n";
                else
                        cout << "YES\n";
        }
        return 0;
}
