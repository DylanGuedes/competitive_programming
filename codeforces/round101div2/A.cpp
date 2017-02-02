#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)

int arr[30];
int other[30];

int main()
{
        ios::sync_with_stdio(false);
        string first, second, third;
        cin >> first >> second >> third;
        memset(arr, 0, sizeof arr);
        memset(other, 0, sizeof other);

        for (auto it : first) {
                arr[it-'A']++;
        }
        for (auto it : second) {
                arr[it-'A']++;
        }

        for (auto it : third) {
                other[it-'A']++;
        }

        bool possible = true;
        rep(i, 0, 26) {
                if (other[i]!=arr[i]) {
                        possible = false;
                }
        }

        if (possible) {
                cout << "YES\n";
        } else {
                cout << "NO\n";
        }
        return 0;
}
