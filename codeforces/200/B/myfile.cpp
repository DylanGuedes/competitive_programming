#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)

int main()
{
        ios::sync_with_stdio(false);
        int n;
        cin >> n;
        int val;
        double result=0;
        rep(i, 0, n) {
                cin >> val;
                result+=val;
        }
        cout << fixed << setprecision(7) << (result/n) << "\n";
        return 0;
}
