#include <iostream>
#include <cstring>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

using ll = long long;
string mys[110];
int val[110];
int ptr[110];
int times[110];

int main()
{
        string s;
        int n, m;
        scanf("%d", &n);
        cin >> s;
        scanf("%d", &m);
        FOR(i, 0, m) {
                cin >> mys[i];
                scanf("%d", &val[i]);
        }
        memset(ptr, 0, sizeof ptr);
        memset(times, 0, sizeof times);
        int x;
        scanf("%d", &x);
        ll total = 0;
        for (auto it : s) {
                printf("char: %c\n", it);
                FOR(i, 0, m) {
                        if (times[i] >= x)
                                continue;
                        if (it == mys[i][ptr[i]]) {
                                ptr[i]++;
                        } else {
                                if (it == mys[i][0]) {
                                        ptr[i] = 1;
                                } else {
                                        ptr[i] = 0;
                                }
                        }

                        if (ptr[i] == mys[i].size()) {
                                printf("worked for %d...\n", i);
                                total+=val[i];
                                ptr[i] = 0;
                                times[i]++;
                        }
                }
        }
        cout << total << "\n";
        return 0;
}
