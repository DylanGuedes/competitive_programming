#include <bits/stdc++.h>

using namespace std;

#define repd(i, j, k)for(int i=j;i>k;i--)
#define repi(i, j, k)for(int i=j;i<k;++i)
#define pb push_back

string other;
int main()
{
        ios::sync_with_stdio(false);
        int n, t;
        cin >> n >> t;
        string mys;
        cin >> mys;
        int len = mys.size();
        repi(j, 0, t) {
                other = mys;
                repd(i, len-1, 0) {
                        if (mys[i]=='G' && mys[i-1]=='B') {
                                other[i] = 'B';
                                other[i-1] = 'G';
                        }
                }
                mys = other;
        }
        cout << mys << "\n";
        return 0;
}
