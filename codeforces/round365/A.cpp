#include <iostream>

using namespace std;

#define FOR(i,j,k)for(int i=j;i<k;++i)

int main()
{
    int n, x, y;
    int mish=0, chris=0;
    cin >> n;
    FOR(z, 0, n) {
        cin >> x;
        cin >> y;
        if (x>y)
            mish+=1;
        else if (y>x)
            chris+=1;
    }
    if (mish>chris)
        cout << "Mishka" << "\n";
    else if (chris>mish)
        cout << "Chris" << "\n";
    else
        cout << "Friendship is magic!^^" << "\n";

    return 0;
}
