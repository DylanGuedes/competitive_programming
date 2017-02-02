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
#define repd(i, j, k)for(int i=k;i>=j;i--)

struct soda {
        int a, b;
};
soda arr[105];
bool myfunc(struct soda s1, struct soda s2)
{
        return s1.b>s2.b;
        // int diff1=s1.b-s1.a;
        // int diff2=s2.b-s2.a;
        // return diff1>diff2;
}

int solve(int left, int right)
{
        if (left>right)
                return 0;
        if (left==right)
                return 0;
        int much=arr[left].b-arr[left].a;
        int taken=min(much, arr[right].a);
        arr[right].a-=taken;
        arr[left].a+=taken;
        int next_left=left, next_right=right;
        int mytime=0;
        mytime+=taken;
        if (arr[left].a==arr[left].b)
                next_left=left+1;
        if (arr[right].a==0) {
                next_right=right-1;
        }
        return mytime+solve(next_left, next_right);
}

int n;
int main()
{
        ios::sync_with_stdio(false);
        cin >> n;
        int atm=0;
        int vol=0;
        rep(i, 0, n) {
                cin >> arr[i].a;
        }
        rep(i, 0, n) {
                cin >> arr[i].b;
        }
        sort(arr, arr+n, myfunc);
        int totaltime=solve(0, n-1);
        int total=0;
        rep(i, 0, n) {
                if (arr[i].a) {
                        total++;
                } else {
                        break;
                }
        }
        cout << total << " " << totaltime<< "\n";
        return 0;
}
