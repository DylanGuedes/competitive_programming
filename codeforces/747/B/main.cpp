#include <bits/stdc++.h>

using namespace std;

double const eps=1e-8;
using ll = long long;
using ii = pair<int, int>;
#define rep(i, j, k)for(int i=j;i<k;++i)
#define pb push_back
#define ins insert
#define mp make_pair
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define debug(x) cout << #x << " = " << x << endl

int n;
string str;

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;
        cin >> str;
        int tries=0;
        map<char, int> dict;
        dict.emplace('A', 0);
        dict.emplace('G', 0);
        dict.emplace('C', 0);
        dict.emplace('T', 0);

        if (str.size()%4 != 0) {
                cout << "===\n";
        } else {
                for (auto it : str) {
                        if (it == '?')
                                tries++;
                        else {
                                dict[it]++;
                        }
                }

                int maxappear=-1<<30;
                for (auto it : dict) {
                        if (it.second>maxappear)
                                maxappear=it.second;
                }
                int needed=0;
                for (auto it : dict) {
                        needed+=(maxappear-it.second);
                }
                if (needed>tries) {
                        cout << "===\n";
                } else {
                        for (auto ch : str) {
                                if (ch=='?') {
                                        bool used=false;
                                        for (auto &it : dict) {
                                                if (it.second<maxappear) {
                                                        cout << it.first;
                                                        it.second++;
                                                        used=true;
                                                        break;
                                                }
                                        }
                                        if (used==false) {
                                                dict['A']++;
                                                maxappear++;
                                                cout << 'A';
                                        }
                                } else {
                                        cout << ch;
                                }
                        }
                }
        }

        return 0;
}
