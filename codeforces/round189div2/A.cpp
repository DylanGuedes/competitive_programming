#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)

int main()
{
        ios::sync_with_stdio(false);
        string mys;
        cin >> mys;
        int len = mys.size();
        bool possible = true;
        rep(i, 0, len) {
                if (mys[i] == '1')
                        continue;
                if (i)
                        if (mys[i]=='4' && mys[i-1]=='1') {
                                continue;
                        }

                if (i>1) {
                        if (mys[i]=='4' && mys[i-1]=='4' && mys[i-2]=='1') {
                                continue;
                        }
                }

                possible = false;
        }
        if (possible)
                cout << "YES\n";
        else
                cout << "NO\n";
        return 0;
}
