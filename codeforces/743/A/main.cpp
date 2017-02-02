#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
#define pb push_back

int main()
{
        ios::sync_with_stdio(false);
        int n, a, b;
        cin >> n >> a >> b;
        string str;
        cin >> str;

        if (str[a-1]!=str[b-1]) {
                cout << 1 << "\n";
        } else {
                cout << 0 << "\n";
        }

        return 0;
}
