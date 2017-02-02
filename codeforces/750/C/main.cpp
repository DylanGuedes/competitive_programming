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

#define MAX 200005
int change[MAX];
int division[MAX];
int n;
set<int> myset;

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;
        bool impossible=false;
        int prev=-1;
        int actual=-1;
        bool poss=true;
        ll ans=-1<<30;
        bool skip=false;
        rep(i, 0, n) {
                cin >> change[i] >> division[i];
                if (division[i]==2) {
                        poss=false;
                }
                if (i && division[i]==2 && division[i-1]==1 && change[i-1]>=0) {
                        skip=true;
                }
        }
        if (poss) {
                cout << "Infinity\n";
        } else {
                bool has_ans=false;
                if (skip) {
                        cout << "Impossible\n";
                        return 0;
                } else {
                        int hi=1<<30;
                        int lo=-1<<30;
                        ll mi=(hi+lo)/2;
                        ll that=0;
                        while (hi>=lo) {
                                mi=(hi+lo)/2;
                                that=mi;

                                // debug(hi);
                                // debug(lo);

                                bool increase=false;
                                bool decrease=false;
                                rep(i, 0, n) {
                                        // if (mi==1906) {
                                        //         debug(that);
                                        // }
                                        if (division[i]==1 && that<1900) {
                                                increase=true;
                                                break;
                                        }
                                        if (division[i]==2 && that>=1900) {
                                                decrease=true;
                                                break;
                                        }
                                        that+=change[i];
                                }

                                if (increase) {
                                        lo=mi+1;
                                } else if (decrease) {
                                        hi=mi-1;
                                } else {
                                        ans=max(ans, (ll)mi);
                                        has_ans=true;
                                        lo=mi+1;
                                }
                        }
                }
                if (has_ans==false) {
                        cout << "Impossible\n";
                } else {
                        rep(i, 0, n) {
                                ans+=(change[i]);
                        }
                        cout << ans<< "\n";
                }
        }
        return 0;
}
