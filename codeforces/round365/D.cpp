#include<iostream>
#include<algorithm>
using namespace std;

#include<string.h>
#include<math.h>

#define N 3000000
#define MAX 3000000
#define inf 0x7fffffff

int arr[N];
int tree[MAX];
#define FOR(i, j,k)for(int i=j;i<k;++i)

void build_tree(int node, int a, int b) {
    if(a > b) return; // Out of range

    if(a == b) { // Leaf node
        tree[node] = arr[a]; // Init value
        return;
    }

    build_tree(node*2, a, (a+b)/2); // Init left child
    build_tree(node*2+1, 1+(a+b)/2, b); // Init right child

    tree[node] = tree[node*2] xor tree[node*2+1]; // Init root value
}

void update_tree(int node, int a, int b, int i, int j, int value) {

    if(a > b || a > j || b < i) // Current segment is not within range [i, j]
        return;

    if(a == b) { // Leaf node
        tree[node] += value;
        return;
    }

    update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
    update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

    tree[node] = tree[node*2] xor tree[node*2+1]; // Updating root with max value
}

int query_tree(int node, int a, int b, int i, int j) {

    if(a > b || a > j || b < i) return -inf; // Out of range

    if(a >= i && b <= j) // Current segment is totally within range [i, j]
        return tree[node];

    int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
    int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

    int res = q1 xor q2; // Return final result

    return res;
}

int main()
{
    int n, m, left, right;
    cin >> n;
    FOR(z, 0, n) {
        cin >> arr[z];
    }
    build_tree(1,0,n-1);
    cin >> m;
    FOR(j, 0, m) {
        cin >> left >> right;
        cout << query_tree(1,0,n-1,left-1,right-1) << "\n";
    }

    return 0;
}
