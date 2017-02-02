#include <bits/stdc++.h>

using namespace std;

double const eps=1e-8;
using ll = long long;
using ii = pair<int, int>;
#define rep(i, j, k)for(int i=j;i<k;++i)
#define pb push_back
#define ins insert
#define mp make_pair
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define debug(x) cout << #x << " = " << x << endl

int n, m;
string str;
int arr[110];
int appear[300];

int main()
{
        ios::sync_with_stdio(false);

        cin >> str;
        memset(appear, 0, sizeof appear);
        for (auto it : str) {
                appear[it-'A']++;
        }

        set<int> myset;

        myset.insert(appear['B'-'A']);
        myset.insert(appear['u'-'A']/2);
        myset.insert(appear['l'-'A']);
        myset.insert(appear['b'-'A']);
        myset.insert(appear['a'-'A']/2);
        myset.insert(appear['s'-'A']);
        myset.insert(appear['r'-'A']);

        if (*myset.begin()==0) {
                cout << "0\n";
        } else {
                cout << *myset.begin() << "\n";
        }

        return 0;
}
