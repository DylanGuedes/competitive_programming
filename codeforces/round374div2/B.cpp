#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
#define repd(i, j, k)for(int i=j;i>=k;i--)
#define pb(i) push_back(i)

bool myfunc(string s1, string s2)
{
        return s1.size() < s2.size();
}

int main()
{
        ios::sync_with_stdio(false);
        int n, k;
        cin >> n >> k;
        string mystr;
        vector<string> myv;
        repi(i, 0, n) {
                cin >> mystr;
                myv.pb(mystr);
        }

        string correct;
        cin >> correct;

        sort(myv.begin(), myv.end(), myfunc);

        int spending = 0;
        int menor = 1<<30;
        int maior = -1<<30;
        int total = 0;

        for (auto it : myv) {
                if (spending>=k) {
                        spending = 0;
                        total += 5;
                }
                total++;
                if (it.size() != correct.size()) {
                        spending++;
                } else {
                        spending++;
                        menor = min(total, menor);
                        maior = max(maior, total);
                }
        }

        cout << menor  << " " << maior << "\n";


        return 0;
}
