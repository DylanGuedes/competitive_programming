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
        int a;
        string b;
        string e;
        string rest;
        char buf;
        int val;

        cin >> a >> buf >> rest;
        int len=rest.size();
        for (int i=len-1;i>=0;i--) {
                if (rest[i]=='e')
                        break;
                e.pb(rest[i]);
        }
        while (rest.back()!='e')
                rest.pop_back();
        rest.pop_back();

        reverse(all(e));
        stringstream iss(e);
        iss >> val;

        len=rest.size();
        if (len && !(len==1 && rest[0]=='0')) {
                if (val) {
                        if (a!=0) {
                                cout << a;
                                if (len>val) {
                                        rep(i, 0, val)
                                                cout << rest[i];
                                        cout << ".";
                                        rep(i, val, len)
                                                cout << rest[i];
                                } else {
                                        rep(i, 0, len)
                                                cout << rest[i];
                                        rep(i, 0, val-len)
                                                cout << "0";
                                }
                        } else {
                                if (len>val) {
                                        cout << a;
                                        rep(i, 0, val)
                                                cout << rest[i];
                                        cout << ".";
                                        rep(i, val, len)
                                                cout << rest[i];
                                } else {
                                        rep(i, 0, len)
                                                cout << rest[i];
                                        rep(i, 0, val-len)
                                                cout << "0";
                                }
                        }
                } else {
                        cout << a;
                        if (rest.size()) {
                                cout << "." << rest;
                        }
                }
        } else {
                if (a&&val)
                        cout << a;
                else
                        cout << "0";

                rep(i, 0, val)
                        cout << "0";
        }
        cout << "\n";
        return 0;
}
