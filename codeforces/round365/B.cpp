#include <iostream>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

#define FOR(i, j,k)for(int i=j;i<k;++i)

int c[100011];
bool capitals[100011];

int main()
{
    int n, k;
    int aux;
    vector<int> myset;
    memset(capitals, 0, sizeof capitals);
    cin >> n >> k;
    FOR(z, 1, n+1) {
        scanf("%d", &c[z]);
    }
    FOR(z, 0, k) {
        scanf("%d", &aux);
        capitals[aux] = 1;
        myset.push_back(aux);
    }

    long long int total=0;
    FOR(i, 1, n) {
        total+=c[i]*c[i+1];
    }
    total+=c[1]*c[n];

    int mysize=myset.size();
    FOR(i, 0, mysize) {
        FOR(j, 1, n+1) {
            if (j==myset[i] || j==myset[i]+1 || myset[i]==j+1 || j==n&&myset[i]==1 || j==1&&myset[i]==n) {
                continue;
            }
            if (capitals[j]) {
                if (myset[i]<j)
                    continue;
            }
            total+=c[myset[i]]*c[j];
        }
    }

    cout << total << "\n";
    return 0;
}
