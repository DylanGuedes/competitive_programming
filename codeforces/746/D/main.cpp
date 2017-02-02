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

int n;
string str;

int main()
{
        ios::sync_with_stdio(false);
        int k, a, b;
        cin >> n >> k >> a >> b;

        priority_queue<char> pq1;
        priority_queue<char> pq2;
        rep(i, 0, a) {
                pq1.push('G');
        }
        rep(i, 0, b) {
                pq2.push('B');
        }

        bool evadepq1=false;
        bool evadepq2=false;
        while (not pq1.empty() && not pq2.empty()) {
                if (pq1.size() > pq2.size()) {
                        if (evadepq1==true) {
                                str.pb(pq2.top());
                                pq2.pop();
                                evadepq1=false;
                        } else {
                                evadepq1=true;
                                evadepq2=false;
                        }
                        rep(i, 0, k) {
                                if (pq1.empty())
                                        break;
                                str.pb(pq1.top());
                                pq1.pop();
                        }
                } else {
                        if (evadepq2==true) {
                                str.pb(pq1.top());
                                pq1.pop();
                                evadepq2=false;
                                continue;
                        } else {
                                evadepq2=true;
                                evadepq1=false;
                        }
                        rep(i, 0, k) {
                                if (pq2.empty())
                                        break;
                                str.pb(pq2.top());
                                pq2.pop();
                        }
                }
        }
        if (pq1.size()+pq2.size() > k) {
                cout << "NO\n";
                return 0;
        } else {
                while (not pq2.empty()) {
                        str.pb(pq2.top());
                        pq2.pop();
                }
                while (not pq1.empty()) {
                        str.pb(pq1.top());
                        pq1.pop();
                }
        }
        cout << str << "\n";
        return 0;
}
