#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
int appear[40];
using ll = long long;

int main()
{
        ios::sync_with_stdio(false);
        string str;
        cin >> str;
        int len=str.size();
        memset(appear, 0, sizeof appear);
        ll chances=0;
        bool good_ans=false;
        rep(i, 0, len-25) {
                if (good_ans)
                        break;
                chances=0;
                memset(appear, 0, sizeof appear);
                rep(j, i, i+26) {
                        if (str[j]=='?')
                                chances++;
                        else
                                appear[str[j]-'A']++;
                }

                bool to_next=false;
                rep(i, 0, 26) {
                        if (appear[i]>1) {
                                to_next=true;;
                        }
                        if (appear[i]==0) {
                                chances--;
                        }
                }
                if (chances<0) {
                        to_next=true;
                }
                if (to_next)
                        continue;
                else {
                        queue<char> myq;
                        rep(i, 0, 26) {
                                if (appear[i]==0) {
                                        myq.push('A'+i);
                                }
                        }
                        rep(j, i, i+26) {
                                if (str[j]=='?') {
                                        str[j]=myq.front();
                                        myq.pop();
                                }
                        }
                        good_ans=true;
                }
        }

        if (good_ans) {
                rep(i, 0, len) {
                        if (str[i]=='?')
                                cout << 'A';
                        else
                                cout << str[i];
                }
                cout << "\n";
        } else {
                cout << -1 << "\n";
        }

        return 0;
}
