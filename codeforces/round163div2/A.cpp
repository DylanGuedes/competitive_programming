#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)

int main()
{
        ios::sync_with_stdio(false);
        int n;
        string mys;
        cin >> n;
        cin >> mys;
        char last = mys[0];
        int len = mys.size();
        int total = 0;
        rep(i, 1, n) {
                last = mys[i-1];
                if (mys[i] == last) {
                        total++;
                }
        }
        cout << total << "\n";
}
