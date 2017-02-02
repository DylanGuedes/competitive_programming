#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define FOR(i, j, k)for(int i=j;i<k;++i)
#define ii pair<int, int>

using namespace std;
vector<ii> arr;
vector<ii> player[101];
double media;

int main()
{
    int n;
    int total = 0, aux;
    cin >> n;
    arr.clear();
    FOR(i, 0, n) {
        scanf("%d", &aux);
        arr.push_back(make_pair(aux, i+1));
        total += aux;
    }

    sort(arr.begin(), arr.end(), less<ii>());
    media = total/n;
    int totalsize = arr.size();
    int part = 0;

    FOR(i, 0, n/2) {
        printf("%d %d\n", arr[i].second, arr[n-1-i].second);
    }
    return 0;
}
