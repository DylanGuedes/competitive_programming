#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
#define pb push_back
#define ep emplace_back
using ll = long long;
using ii = pair<int, int>;
#define all(x) x.begin(),x.end()
#define repd(i, j, k)for(int i=j;i>=k;i--)
double const pi = acos(-1.0);
double const eps = 1e-10;
int const oo = 1<<30;

double equals(double a, double b)
{
        return fabs(a-b)<eps;
}

class pt {
public:
        double x, y;
        pt() { }
};

pt arr[1010];

double myfunc(pt p, pt q)
{
        if (equals(p.x, q.x))
                return p.y<q.y;
        return p.x<q.x;
}

class Line {
public:
        double a;
        double b;
        double c;
        pt A, B;

        Line(double av, double bv, double cv) : a(av), b(bv), c(cv) {}

        Line(const pt& p, const pt& q) : A(p),B(q)
        {
                a = p.y - q.y;
                b = q.x - p.x;
                c = p.x * q.y - p.y * q.x;

                auto k = a ? a : b;

                a /= k;
                b /= k;
                c /= k;
        }

        bool parallel(const Line& r) const
        {
                return equals(a, r.a) && equals(b, r.b) && !equals(c, r.c);
        }

        double length() const
        {
                return hypot(A.x - B.x, A.y - B.y);
        }
};

vector<Line> lines;
int main()
{
        ios::sync_with_stdio(false);
        int t, n;
        cin >> t;
        rep(z, 0, t) {
                cin >> n;
                rep(i, 0, n) {
                        cin >> arr[i].x >> arr[i].y;
                }
                double highest_area=0.0;

                sort(arr, arr+n, myfunc);

                rep(i, 0, n) {
                        int j=i+1;
                        int k=i+2;
                        int l=i+3;
                        if (j==n || k==n || l==n)
                                break;
                        lines.clear();
                        lines.pb(Line(arr[i], arr[j]));
                        lines.pb(Line(arr[i], arr[k]));
                        lines.pb(Line(arr[i], arr[l]));
                        lines.pb(Line(arr[j], arr[k]));
                        lines.pb(Line(arr[j], arr[l]));
                        lines.pb(Line(arr[k], arr[l]));

                        bool parallel=false;
                        bool candidate=true;
                        double dist=-1000000.0;
                        bool its=false;
                        double highest=-10000000.0;
                        double lowest=10000000.0;
                        int idx=-1, idx_low=-1;

                        cout << "TAMANHO DAS INHAs: \n";
                        for (auto it : lines) {
                                cout << it.length() << "\n";
                        }

                        rep(p, 0, 6) {
                                rep(q, p+1, 6) {
                                        its = lines[p].parallel(lines[q]);
                                        if (parallel && its) {
                                                candidate=false;
                                                break;
                                        } else if (its) {
                                                dist=(double)fabs((double)lines[p].c-lines[q].c)/hypot(lines[p].a, lines[p].b);
                                                parallel=true;

                                                cout << "lines["<<p<<"].length= "<<lines[p].length() << "\n";
                                                cout << "lines["<<q<<"].length= "<<lines[q].length() << "\n";
                                                if (lines[p].length()>highest) {
                                                        idx=p;
                                                        highest=lines[p].length();
                                                }
                                                if (lines[q].length()>highest) {
                                                        idx=q;
                                                        highest=lines[q].length();
                                                }
                                                if (lines[p].length()<lowest) {
                                                        idx_low=p;
                                                        lowest=lines[p].length();
                                                }
                                                if (lines[q].length()<lowest) {
                                                        idx_low=q;
                                                        lowest=lines[q].length();
                                                }
                                        }
                                }
                        }

                        if (not candidate || not parallel)
                                break;

                        cout << "highest: " << highest << ", lowest: " << lowest << "\n";
                        double actual_area = 0.5*(highest+lowest)*dist;
                        if (actual_area > highest_area) {
                                highest_area = actual_area;
                        }
                }
                cout << "Caso " << z+1 << ": " << fixed << setprecision(2) << highest_area << "\n";
        }
        return 0;
}
