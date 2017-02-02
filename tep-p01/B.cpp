#include <bits/stdc++.h>
#define FOR(i, j, k)for(int i=j;i<k;++i)

using namespace std;

double const EPS = 1e-10;

double equals(double a1, double a2)
{
        return fabs(a1-a2) < EPS;
}

class Point {
public:
        int x, y;
        Point(int _x, int _y) : x(_x), y(_y) { }
        Point() { }
};

double D(Point P, Point Q, Point R)
{
        return (P.x*Q.y + P.y*R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);

}

int main()
{
        ios::sync_with_stdio(false);
        int px, py, qx, qy, n, r_int, r_double, counter=0;
        char buf;

        while (cin >> px >> py >> qx >> qy) {
                cin >> r_int >> buf >> r_double;
                Point p(px, py);
                Point q(qx, qy);

                cin >> n;
                Point e;
                int wrong = 0;
                FOR(i, 0, n) {
                        cin >> e.x >> e.y;
                        if (not equals(D(p, q, e), 0)) {
                                wrong++;
                        }
                }
                int complete = (r_int*100+r_double)*wrong;

                if (counter)
                        cout << "\n";
                cout << "Caso #" << counter+1<< ":\n";
                cout << wrong << " estaca(s) desalinhada(s)\n";
                if (wrong)
                        cout << "Custo: R$ " << complete/100 << "," << complete%100 << ((complete%100<10) ? ("0") : "") << "\n";
                else
                        cout << "Bom trabalho!\n";
                counter++;
        }
        return 0;
}
