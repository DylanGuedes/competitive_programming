#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
#define pb push_back

const double eps=1e-8;
double equals(double a, double b)
{
        return fabs(a-b)<eps;
}
using ll = long long;

int main()
{
        ios::sync_with_stdio(false);
        int n;
        cin >> n;
        if (n==1)
                cout << -1 << "\n";
        else
                cout << n << " " << n+1 << " " << n*(n+1) << "\n";
        return 0;
}
