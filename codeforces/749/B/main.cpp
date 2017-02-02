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

class point {
public:
        int x, y;
        point(){}
        point(int _x, int _y):x(_x),y(_y){}
};

int D(const point& P, const point& Q, const point& R)
{
        return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

int main()
{
        ios::sync_with_stdio(false);
        point pt[3];
        int highest_y=-1<<30;
        int highest_x=-1<<30;
        rep(i, 0, 3) {
                cin >> pt[i].x >> pt[i].y;
                highest_y=max(highest_y, pt[i].y);
                highest_x=max(highest_x, pt[i].x);

        }
        point dummy;
        int minval=1<<30;
        set<ii> myv;

        rep(i, 0, 3) {
                vector<ii> tries {mp(pt[i].x+1, pt[i].y), mp(pt[i].x-1, pt[i].y), mp(pt[i].x, pt[i].y-1), mp(pt[i].x, pt[i].y+1) };
                for (auto node : tries) {
                        dummy = point(node.first, node.second);
                        minval = 1<<30;
                        minval=min(minval, abs(D(pt[0], pt[1], dummy)));
                        minval=min(minval, abs(D(pt[1], dummy, pt[2])));
                        minval=min(minval, abs(D(dummy, pt[2], pt[0])));
                        if (minval != 0) {
                                myv.insert(node);
                        }
                }
        }
        cout << myv.size() << "\n";
        for (auto it : myv) {
                cout << it.first << " "<< it.second<< "\n";
        }

        return 0;
}
