#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
#define all(x) x.begin(), x.end()
using ll = long long;
using ii = pair<int, int>;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define emp emplace
#define ins insert
#define repd(i, j, k)for(int i=k;i>=j;i--)

string word[105];
int rgx[105];
bool forbidden[105];
int n, m;
bool used[105];
int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> m;
        rep(i, 0, n) cin >> word[i];

        memset(forbidden, 0, sizeof forbidden);
        rep(i, 0, m) {
                cin >> rgx[i];
                rgx[i]-=1;
                forbidden[rgx[i]]=1;
        }

        int len=word[rgx[0]].size();
        bool possible=true;
        rep(i, 1, m) {
                if (word[rgx[i]].size() != len) {
                        possible=false;
                }
        }

        if (possible) {
                vector<char> target(len, '?');
                memset(used, 0, sizeof used);
                rep(i, 0, m) {
                        rep(j, i+1, m) {
                                rep(k, 0, len) {
                                        string s1=word[rgx[i]];
                                        string s2=word[rgx[j]];
                                        if (s1[k]==s2[k] && target[k]=='?') {
                                                target[k]=s1[k];
                                        } else {
                                                target[k]='?';
                                        }
                                }
                        }
                }
                rep(i, 0, n) {
                        if (forbidden[i])
                                continue;
                        int len2=word[i].size();
                        bool same=true;
                        if (len2==len) {
                                rep(k, 0, len2) {
                                        if (word[i][k]!=target[k] && target[k]!='?') {
                                                same=false;
                                                break;
                                        }
                                }
                        } else {
                                same=false;
                        }
                        if (same) {
                                possible=false;
                                break;
                        }
                }
                if (possible) {
                        cout << "Yes\n";
                        for (auto it : target)
                                cout << it;
                        cout << "\n";
                } else {
                        cout << "No\n";
                }
        } else {
                cout << "No\n";
        }

        return 0;
}
