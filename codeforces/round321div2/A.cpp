#include <iostream>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int n;
int arr[100010];
int lis[100010];

int main()
{
    scanf("%d", &n);
    FOR(i, 0, n) {
        scanf("%d", &arr[i]);
    }

    FOR(i, 0, n)
        lis[i] = 1;

    lis[0] = 1;
    FOR(i, 1, n) {
        if (arr[i] >= arr[i-1])
            lis[i] = max(lis[i-1]+1, lis[i]);
        else
            lis[i] = 1;
    }

    int ans = -0xffffff;
    FOR(i, 0, n) {
        ans = max(ans, lis[i]);
    }

    printf("%d\n", ans);
    return 0;
}
