#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
#define repd(i, j, k)for(int i=j;i>k;i--)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
using ll = long long;
using ii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> myv;
set<int> myset;
map<char, int> mymap;
int n, t, s;

int horario(int a, int b)
{
        // cout << "go\n";
        int total = 0;
        b=b%26;
        a=a%26;
        while (a!=b) {
                // cout << "A :" << a << ", B:" << b << "\n";
                a=(a+1)%26;
                total++;
                if (a==b)
                        break;
        }
        // cout << "return: " << total << "\n";
        return total;
}

int main()
{
        ios::sync_with_stdio(false);
        repi(i, 0, 26)
                mymap.emplace('a'+i, (i+1)%26);
        string mys;
        mys = 'a';
        string other;
        cin >> other;
        mys += other;
        int mysize = mys.size();
        ll total = 0;
        repi(i, 0, mysize-1) {
                int v1 = horario(mymap[mys[i]], mymap[mys[i+1]]);
                int v2 = horario(mymap[mys[i+1]], mymap[mys[i]]);
                total += min(v1, v2);
        }
        cout << total << "\n";
        return 0;
}
