#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

vector<int> laziness;
vector<int> leng;

using ll = long long;

int main()
{
        int n;
        int aux;
        cin >> n;
        FOR(i, 0, n) {
                scanf("%d", &aux);
                leng.push_back(aux);
                laziness.push_back(aux);
        }
        sort(laziness.begin(), laziness.end());
        sort(leng.begin(), leng.end(), greater<int>());

        ll total = 0;

        FOR(i, 0, n) {
                total += ((leng[i]%10007)*(laziness[i]%10007))%10007;
        }

        cout << total%10007 << "\n";

        return 0;
}
