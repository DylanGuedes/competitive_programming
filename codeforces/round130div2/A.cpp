#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int main()
{
        ios::sync_with_stdio(false);
        string s;
        cin >> s;
        int idx=0;
        string ans="";
        int len=s.size();
        bool needs_space = false;
        while (idx<len) {
                if (s[idx]=='W' && s[idx+1]=='U' && s[idx+2]=='B') {
                        needs_space = true;
                        idx+=3;
                } else {
                        if (ans.empty()) {
                                ans.pb(s[idx]);
                        } else {
                                if (needs_space)
                                        ans.pb(' ');
                                ans.pb(s[idx]);
                        }
                        needs_space=false;
                        idx++;
                }
        }
        cout << ans << "\n";
        return 0;
}
