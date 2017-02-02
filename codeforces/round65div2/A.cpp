#include <bits/stdc++.h>

using namespace std;

int main()
{
        ios::sync_with_stdio(false);
        int n;
        cin >> n;
        string mystring;
        for(int i=0; i<n; ++i) {
                cin >> mystring;
                if (mystring.size() <= 10) {
                        cout << mystring <<"\n";
                } else {
                        cout << mystring[0] << mystring.size()-2 << mystring.back() << "\n";
                }
        }

        return 0;
}
