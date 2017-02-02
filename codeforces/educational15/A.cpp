#include <iostream>
#include <cstring>

using namespace std;

long long int arr[100005];
int lis[100005];

#define FOR(i, j, k)for(int i=j;i<k;++i)

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    FOR(i,0,n) {
        cin >> arr[i];
        lis[i] = 1;
    }
    FOR(i, 1, n) {
        for(int j=i-1;j>=0;j--) {
            if(arr[i] > arr[j]) {
                if (j>0) {
                    if(arr[j]<=arr[j-1]) {
                        lis[i]+=1;
                        break;
                    }
                }
                lis[i] += 1;
            } else {
                break;
            }
        }
    }
    int mymax = 0;
    FOR(i, 0, n) {
        mymax = max(mymax, lis[i]);
    }
    cout << mymax << "\n";
    return 0;
}
