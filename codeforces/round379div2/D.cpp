#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
#define all(x) x.begin(), x.end()
using ll = long long;
using ii = pair<int, int>;
#define repd(i, j, k)for(int i=j;i>=k;i--)
#define pb push_back
#define eb emplace_back
#define emp emplace
#define ins insert
#define mp make_pair
double const eps = 1e-10;
double const pi = acos(-1);

class pt {
public:
        ll x, y;
        char t;
        pt() { }
};

vector<pt> incl_1st;
vector<pt> incl_2nd;
vector<pt> incl_3rd;
vector<pt> incl_4th;
vector<pt> myleft;
vector<pt> myright;
vector<pt> upper;
vector<pt> down;

pt king;

double dist(pt a, pt b)
{
        auto v1 = a.x - b.x;
        auto v2 = a.y - b.y;
        return sqrt(v1*v1 + v2*v2);
}

bool upper_sort(pt p1, pt p2)
{
        return abs(p1.y-king.y) < abs(p2.y-king.y);
}

bool down_sort(pt p1, pt p2)
{
        return abs(p1.y-king.y) < abs(p2.y-king.y);
}

bool myright_sort(pt p1, pt p2)
{
        return abs(p1.x-king.x) < abs(p2.x-king.x);
}

bool myleft_sort(pt p1, pt p2)
{
        return abs(p1.x-king.x) < abs(p2.x-king.x);
}

bool incl_1st_sort(pt p1, pt p2)
{
        return abs(p1.x-king.x)+abs(p1.y-king.y) < abs(p2.x-king.x)+abs(p2.y-king.y);
}

int main()
{
        ios::sync_with_stdio(false);

        int n;
        cin >> n;

        cin >> king.x >> king.y;
        pt p;

        rep(i, 0, n) {
                cin >> p.t >> p.x >> p.y;
                if (p.y == king.y) {
                        if (p.x > king.x) {
                                myright.pb(p);
                        } else {
                                myleft.pb(p);
                        }
                }
                if (p.x == king.x) {
                        if (p.y > king.y) {
                                upper.pb(p);
                        } else {
                                down.pb(p);
                        }
                }
                if (abs(p.x-king.x)==abs(p.y-king.y)) {
                        if (p.x>=king.x && p.y>=king.y) {
                                incl_1st.pb(p);
                        } else if(p.x>=king.x && p.y<king.y) {
                                incl_2nd.pb(p);
                        } else if(p.x<king.x && p.y>=king.y) {
                                incl_3rd.pb(p);
                        } else if (p.x<king.x && p.y<king.y) {
                                incl_4th.pb(p);
                        }
                }
        }

        sort(all(upper), upper_sort);
        sort(all(myright), myright_sort);
        sort(all(myleft), myleft_sort);
        sort(all(down), down_sort);
        sort(incl_1st.begin(), incl_1st.end(), incl_1st_sort);
        sort(incl_2nd.begin(), incl_2nd.end(), incl_1st_sort);
        sort(incl_3rd.begin(), incl_3rd.end(), incl_1st_sort);
        sort(incl_4th.begin(), incl_4th.end(), incl_1st_sort);

        bool possible = false;
        if (not myleft.empty() && (myleft[0].t == 'R' || myleft[0].t == 'Q'))
                possible = true;
        else if (not myright.empty() && (myright[0].t == 'R' || myright[0].t == 'Q'))
                possible = true;
        else if (not upper.empty() && (upper[0].t == 'R' || upper[0].t == 'Q'))
                possible = true;
        else if (not down.empty() && (down[0].t == 'R' || down[0].t == 'Q'))
                possible = true;
        else if (not incl_1st.empty() && (incl_1st[0].t=='Q' || incl_1st[0].t=='B'))
                possible = true;
        else if (not incl_2nd.empty() && (incl_2nd[0].t=='Q' || incl_2nd[0].t == 'B'))
                possible = true;
        else if (not incl_3rd.empty() && (incl_3rd[0].t=='Q' || incl_3rd[0].t == 'B'))
                possible = true;
        else if (not incl_4th.empty() && (incl_4th[0].t=='Q' || incl_4th[0].t == 'B'))
                possible = true;

        if (possible == false) {
                cout << "NO\n";
        } else {
                cout << "YES\n";
        }
        return 0;
}
