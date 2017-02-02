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
int x;
int y;

int go_north(int);
int go_south(int);

int go_south(int many)
{
        if (many+y > 20000) {
                y=20000;
                go_north(many%20000);
        } else {
                y+=many;
        }
}

int go_north(int many)
{
        if (y-many < 0) {
                y=0;
                go_south(many%20000);
        } else {
                y-=many;
        }
}


int main()
{
        ios::sync_with_stdio(false);
        cin >> n;
        y=0;
        int aux;
        bool impossible = false;
        x=0;
        int started;
        rep(i, 0, n) {
                cin >> aux >> str;
                aux=(aux%40000);
                // cout << "AUX: "<<aux << "\n";

                started=y;
                if (y==0 && str != "South") {
                        impossible = true;
                }
                if (y==20000 && str != "North") {
                        impossible = true;
                }
                if (str == "South") {
                        go_south(aux);
                } else if (str == "East") {
                        continue;
                } else if (str == "West") {
                        continue;
                } else {
                        go_north(aux);
                }
                // cout << "Y: " << y << "\n";
        }
        if (y!=0) {
                impossible = true;
        }
        if (impossible) {
                cout << "NO\n";
        } else {
                cout << "YES\n";
        }
        return 0;
}
