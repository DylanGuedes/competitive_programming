#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

bool toy[300005];
vector<int> arr;

int main()
{
        int mymax = -1<<30;
        int n, m;
        int aux;
        cin >> n >> m;
        memset(toy, 0, sizeof toy);
        FOR(i, 0, n) {
                scanf("%d", &aux);
                mymax = max(mymax, aux);
                if (aux <= 200000)
                        toy[aux] = true;
        }

        FOR(i, 1, mymax) {
                if (m < i) {
                        break;
                }
                if (not toy[i]) {
                        arr.push_back(i);
                        m -= i;
                }
        }

        int mycounter = mymax+1;
        while (mycounter <= m) {
                m -= mycounter;
                arr.push_back(mycounter);
                mycounter++;
        }

        printf("%d\n", arr.size());
        for (auto it : arr) {
                if (it != *arr.begin())
                        printf(" ");
                printf("%d", it);
        }
        printf("\n");
        return 0;
}
