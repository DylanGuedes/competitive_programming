#include <bits/stdc++.h>

using namespace std;

int n, start;
string str;
int change[100010];

#define rep(i, j, k)for(int i=j;i<k;++i)
#define pb push_back
list<int> myl;

int dist(char A, char B)
{
        if (A == B) {
                return 0;
        } else {
               if (A>B)
                      swap(A, B);
               return min(B-A, A-'a'+1+(B-'z'));
        }
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> start;
        cin >> str;
        auto it=myl.begin();
        rep(i, 0, n/2) {
                change[i]=dist(str[i], str[n-i-1]);
                change[n-i-1]=change[i];
                if (change[i] || start-1==i) {
                        myl.pb(i);
                }
                if (start-1==i) {
                        it=myl.end();
                        it--;
                }
        }
        while (not myl.empty()) {
                int idx=*it;
                auto next=myl.erase(it);
                auto prev=it;
                prev--;
                if (*next-idx < idx-prev) {
                        it=next;
                        total+=(*next-idx);
                        total+=change[n-i-1];
                }
        }
        return 0;
}
