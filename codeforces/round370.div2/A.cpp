#include <iostream>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)
using ll = long long;
ll arr[100005];

int main()
{
        int n;
        cin >> n;
        FOR(i, 0, n) {
                cin >> arr[i];
        }

        FOR(i, 0, n-1) {
                if (i)
                        printf(" ");
                cout << arr[i]+arr[i+1];
        }
        cout << " " << arr[n-1] << "\n";
        return 0;
}

