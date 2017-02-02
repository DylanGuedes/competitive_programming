#include <bits/stdc++.h>

using namespace std;

double const eps=1e-8;
using ll = long long;
using ii = pair<int, int>;
#define rep(i, j, k)for(int i=j;i<k;++i)
#define FOR(i, j, k)for(int i=j;i<k;++i)
#define pb push_back
#define ins insert
#define mp make_pair
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define debug(x) cout << #x << " = " << x << endl

int n, m;
string str;

int main()
{
        ios::sync_with_stdio(false);

        cin >> str;
        str.pb('A');
        set<char> myset;
        myset.insert('A');
        myset.insert('E');
        myset.insert('I');
        myset.insert('O');
        myset.insert('U');
        myset.insert('Y');

        int len=str.size();
        int total=0;
        bool looking=true;
        int d=0;
        int ans=-1<<30;
        rep(i, 0, len) {
                d++;
                if (myset.count(str[i])==0 && looking) {
                        continue;
                } else if (myset.count(str[i])==0 && !looking) {
                        d=1;
                        looking=true;
                } else if (myset.count(str[i])>0 && looking) {
                        looking=false;
                        total+=d;
                        ans=max(ans, d);
                        // debug(d);
                        d=0;
                } else if (myset.count(str[i])>0 && !looking) {
                        continue;
                }
        }

        cout << ans<< "\n";

        return 0;
}
