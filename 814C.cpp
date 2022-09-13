#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1502;
const int ALPHABET = 26;

int n;
char s[MAXN];
int ans[ALPHABET][MAXN] = {{ 0 }};
int q, m_i;
char c_i;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>n;
    for (int i = 0; i < n; ++i) cin>>s[i];

    for (char c = 0; c < ALPHABET; ++c) {
        for (int i = 0; i < n; ++i) {
            int replace_ct = 0;
            for (int j = i; j < n; ++j) {
                if (s[j] - 'a' != c) ++replace_ct;
                ans[c][replace_ct] = std::max(ans[c][replace_ct], j - i + 1);
            }
        }
        for (int i = 1; i < MAXN; ++i)
            ans[c][i] = std::max(ans[c][i], ans[c][i - 1]);
    }

    cin>>q;
    for (int i = 0; i < q; ++i) {
        cin>>m_i>>c_i;
        cout<<ans[c_i - 'a'][m_i]<<'\n';
    }

    return 0;
}