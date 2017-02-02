#include <bits/stdc++.h>

using namespace std;

int main()
{
        string mys;
        ios::sync_with_stdio(false);
        while (cin >> mys) {
                int total = 0;
                for (auto it : mys) {
                        if (total > 7)
                                break;
                        if (it == '4' || it == '7') {
                                total++;
                        }
                }

                if (total == 4 || total == 7) {
                        cout << "YES\n";
                } else {
                        cout << "NO\n";
                }
        }
        return 0;
}
