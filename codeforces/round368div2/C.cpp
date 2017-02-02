#include <iostream>

using namespace std;

using ll = long long;

int main()
{
        ll n;
        cin >> n;
        if (n <= 2)
                cout << "-1" << "\n";
        else {
                if (n&1) {
                        cout << (n*n-1)/2 << " " << (n*n+1)/2 << "\n";
                } else {
                        cout << (n*n/4)-1 << " " << (n*n/4)+1 << "\n";
                }
        }

        return 0;
}
