#include <bits/stdc++.h>

using namespace std;

int arr[100];

int main()
{
        ios::sync_with_stdio(false);
        int n;
        cin >> n;
        for(int i=0; i < n; ++i) {
                cin >> arr[i];
        }
        if (n == 1) {
                if (arr[0] == 0) {
                        cout << "UP\n";
                } else if (arr[0] == 15) {
                        cout << "DOWN\n";
                } else {
                        cout << "-1\n";
                }
        } else if (arr[n-2] > arr[n-1]) {
                if (arr[n-1] == 0) {
                        cout << "UP\n";
                } else {
                        cout << "DOWN\n";
                }
        } else if (arr[n-2] < arr[n-1]) {
                if (arr[n-1] == 15) {
                        cout << "DOWN\n";
                } else {
                        cout << "UP\n";
                }
        }
        return 0;
}
