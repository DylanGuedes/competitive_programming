#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
#define all(x) x.begin(), x.end()
using ll = long long;
using ii = pair<int, int>;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define emp emplace
#define ins insert

int main()
{
        ios::sync_with_stdio(false);
        ll n;
        cin >> n;

        ll myval;
        if (n&1) {
                myval=n/2;
                myval++;
        } else {
                myval=n/2;
                if (myval&1 && myval!=1)
                        myval--;
        }
        cout << myval << "\n";
        return 0;
}
