#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

bool shelf[1005][1005];
stack<int> mystack;
int total = 0;
int n, m;

void revert_op()
{
    int operation = mystack.top(); mystack.pop();
    int n1, n2;
    if (operation == 1) {
        n1 = mystack.top(); mystack.pop();
        n2 = mystack.top(); mystack.pop();
        if (shelf[n1][n2])
            total -= 1;
        shelf[n1][n2] = 0;
    } else if (operation == 2) {
        n1 = mystack.top(); mystack.pop();
        n2 = mystack.top(); mystack.pop();
        if (not shelf[n1][n2])
            total -= 1;
        shelf[n1][n2] = 1;
    } else if (operation == 3) {
        n1 = mystack.top(); mystack.pop();
        FOR(i, 0, m) {
            if (shelf[n1][i])
                total -= 1;
            else
                total += 1;
            shelf[n1][i] = not shelf[n1][i];
        }
    }
}

int main()
{
    int q;
    int n1, n2;
    int operation;
    scanf("%d%d%d", &n, &m, &q);
    memset(shelf, 0, sizeof shelf);
    FOR(z, 0, q) {
        scanf("%d", &operation);
        if (operation == 1) {
            scanf("%d%d", &n1, &n2);
            n1 -= 1;
            n2 -= 1;
            if (not shelf[n1][n2])
                total+=1;
            shelf[n1][n2] = 1;
            mystack.push(n2);
            mystack.push(n1);
            mystack.push(operation);
        } else if (operation == 2) {
            scanf("%d%d", &n1, &n2);
            n1 -= 1;
            n2 -= 1;
            if (shelf[n1][n2])
                total-=1;
            shelf[n1][n2] = 0;
            mystack.push(n2);
            mystack.push(n1);
            mystack.push(operation);
        } else if (operation == 3) {
            scanf("%d", &n1);
            n1 -= 1;
            FOR(i, 0, m) {
                if (shelf[n1][i])
                    total -= 1;
                else
                    total += 1;
                shelf[n1][i] = not shelf[n1][i];
            }
            mystack.push(n1);
            mystack.push(operation);
        } else if (operation == 4) {
            scanf("%d", &n1);
            FOR(n1, 0, z)
                revert_op();
        }
        if (total < 0)
            printf("0\n");
        printf("%d\n", total);
    }

    return 0;
}
