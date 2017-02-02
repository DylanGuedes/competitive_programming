#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)
long long int arr[100005];
bool poweroftwo(long long int num)
{
    return (num & num-1)==0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    FOR(i, 0, n) {
        cin >> arr[i];
    }
    long long int total = 0;
    sort(arr, arr+n);
    FOR(i, 0, n) {
        FOR(j, i+1, n) {
            if (poweroftwo(arr[i]+arr[j])) {
                total+=1;
            }
        }
    }
    cout << total << "\n";
    return 0;
}
