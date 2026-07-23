**Time Complexity:** *O(N × M),* **Space Complexity:** *O(N × M).*

```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t; cin>>s>>t;
    int N = s.size();
    int M = t.size();
    vector<vector<int>> dp(N+1, vector<int>(M+1, 0));
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string lcs;
    for(int i=N, j=M; i>0 && j>0;) {
        if(s[i-1] == t[j-1]) {
            lcs.push_back(s[i-1]);
            i--;
            j--;
        } else if(dp[i-1][j] >= dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    
    reverse(lcs.begin(), lcs.end());
    cout<<lcs<<"\n";
    return 0;
}
```