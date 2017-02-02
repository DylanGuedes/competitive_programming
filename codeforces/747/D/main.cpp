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

int n, k;
string str;
#define MAX 200020
int temp[MAX];
#define summer 1

int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> k;
        int aux;
        int inc=1;
        cin >> aux;

        vector<pair<char, int> > myv;
        int prev;
        if (aux>=0)
                prev=1;
        else
                prev=-1;

        rep(i, 1, n) {
                cin >> aux;
                if (aux>=0) {
                        if (prev==1) {
                                inc++;
                        } else {
                                myv.eb('-', inc);
                                inc=1;
                                prev=1;
                        }
                } else {
                        if (prev==-1) {
                                inc++;
                        } else {
                                myv.eb('+', inc);
                                inc=1;
                                prev=-1;
                        }
                }
        }
        if (prev==1)
                myv.eb('+', inc);
        else
                myv.eb('-', inc);

        int idx=0;
        int tire=summer;
        int len=myv.size();
        int changes=0;
        int rem=0;

        while (idx<len) {
                debug(idx);
                debug(changes);
                debug(tire);
                debug(rem);
                cout << "------\n";
                if (myv[idx].first=='-') {
                        if (tire==summer) {
                                tire=!summer;
                                rem=k-myv[idx].second-1;
                                changes++;
                                if (rem<0) {
                                        cout << -1 << "\n";
                                        return 0;
                                }
                        } else {
                                rem=rem-myv[idx].second;
                                if (rem<0) {
                                        cout << -1 << "\n";
                                        return 0;
                                }
                        }
                } else {
                        if (!(tire==summer)) {
                                rem=rem-myv[idx].second;
                                if (rem<0) {
                                        changes++;
                                        tire=summer;
                                }
                        }
                }
                idx++;
        }

        cout << changes << "\n";

        return 0;
}
