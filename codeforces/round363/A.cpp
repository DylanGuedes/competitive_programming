#include <iostream>

using namespace std;

char sym[200010];
int x[200010];

#define FOR(i, j, k)for(int i=j;i<k;++i)

int main()
{
    int n;
    cin >> n;
    getchar();
    FOR(i, 0, n) {
        scanf("%c", &sym[i]);
    }

    FOR(i, 0, n) {
        scanf("%d", &x[i]);
    }

    bool collision = false;
    int sol = 1 << 30;

    FOR(i, 0, n-1) {
        if (sym[i] == sym[i+1])
            continue;

        if ((x[i] < x[i+1] && sym[i] == 'R' && sym[i+1] == 'L') || (x[i] > x[i+1] && sym[i] == 'L' && sym[i+1] == 'R'))
        {
            int collision_pos = (x[i]+x[i+1])/2;

            int collision_time = collision_pos - min(x[i], x[i+1]);
            collision = true;
            sol = min(sol, collision_time);
        }
    }

    if (collision)
        printf("%d\n", sol);
    else
        printf("-1\n");

}
