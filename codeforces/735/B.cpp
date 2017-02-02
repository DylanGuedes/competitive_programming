#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
#define all(x) x.begin(), x.end()
using ll = long long;
using ii = pair<int, int>;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define emp emplace
#define ins insert

int main()
{
        ios::sync_with_stdio(false);
        int n, n1, n2;
        cin >> n >> n1 >> n2;
        int p[100005];
        int aux;
        priority_queue<int> mypq;
        rep(i, 0, n) {
                cin >> aux;
                mypq.emplace(aux);
        }
        int mymin=min(n1, n2);
        int mymax=max(n1, n2);
        int k=mymin;
        double total=0;
        double part=0;
        while (k) {
                part+=mypq.top();
                mypq.pop();
                k--;
        }
        part/=mymin;
        total=part;
        k=mymax;
        part=0;
        while (k) {
                part+=mypq.top();
                mypq.pop();
                k--;
        }
        part/=mymax;
        total+=part;
        cout <<fixed << setprecision(7)<< total << "\n";
        return 0;
}
