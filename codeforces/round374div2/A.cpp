#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
#define repd(i, j, k)for(int i=j;i>=k;i--)
#define pb(i) push_back(i)

int main()
{
        ios::sync_with_stdio(false);
        int k;
        cin >> k;
        string mystr;
        cin >> mystr;
        int str_size = mystr.size();
        int b = 0;
        int counter = 0;
        vector<int> myv;
        repi(i, 0, str_size) {
                if (mystr[i] == 'B')
                        counter++;
                else {
                        if (counter) {
                                myv.push_back(counter);
                                counter = 0;
                        }
                }
        }
        if (counter)
                myv.push_back(counter);
        cout << myv.size() << "\n";
        int v_size = myv.size();
        if (v_size) {
                repi(j, 0, v_size) {
                        if (j)
                                cout << " ";
                        cout << myv[j];
                }
                cout << "\n";
        }
        return 0;
}
