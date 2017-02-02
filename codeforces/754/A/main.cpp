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

int main()
{
        ios::sync_with_stdio(false);

        cin >> n;
        rep(i, 0, n) {
                cin >> arr[i];
        }

        if (n==1) {
                if (arr[0] == 0) {
                        cout << "NO\n";
                } else {
                        cout << "YES\n";
                        cout << 1 << "\n";
                        cout << 1 << " " << 1 << "\n";
                }
        } else {
                int accum=0;
                vector<ii> res;
                bool evade=false;
                rep(i, 0, n) {
                        evade=true;
                        accum=arr[i];
                        if (arr[i]==0) {
                                evade=false;
                        }
                        bool changed=false;
                        rep(j, i+1, n) {
                                accum+=arr[j];
                                if (evade==false) {
                                        if (accum!=0) {
                                                evade=true;
                                        }
                                } else {
                                        if (accum==0) {
                                                res.eb(i, j-1);
                                                i=j-1;
                                                changed=true;
                                                break;
                                        }
                                }
                        }
                        if (!changed) {
                                if (accum!=0) {
                                        res.eb(i, n-1);
                                }
                                break;
                        }
                        if (i==n-1) {
                                if (accum!=0) {
                                        res.eb(i, n-1);
                                        break;
                                } else {
                                        cout << "NO\n";
                                        return 0;
                                }
                        }
                }

                if (res.empty()) {
                        cout << "NO\n";
                } else {
                        cout << "YES\n";
                        cout << res.size() << "\n";
                        for (auto it : res) {
                                cout << it.first+1 << " " << it.second+1 << "\n";
                        }
                }
        }

        return 0;
}
