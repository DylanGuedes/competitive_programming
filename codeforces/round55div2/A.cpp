#include <bits/stdc++.h>

using namespace std;
#define rep(i, j, k)for(int i=j;i<k;++i)

int main()
{
        ios::sync_with_stdio(false);
        string mys;
        cin >> mys;
        int lower=0;
        int higher=0;
        for (auto it : mys) {
                if (it >= 'a' && it <= 'z') {
                        lower++;
                }

                if (it >= 'A' && it <= 'Z') {
                        higher++;
                }
        }

        int len = mys.size();
        if (lower >= higher) {
                rep(i, 0, len) {
                        if (mys[i] >= 'A' && mys[i] <= 'Z') {
                                mys[i]+=('a'-'A');
                        }
                }
        } else {
                rep(i, 0, len) {
                        if (mys[i] >= 'a' && mys[i] <= 'z') {
                                mys[i]-=('a'-'A');
                        }
                }
        }

        cout << mys << "\n";

}
