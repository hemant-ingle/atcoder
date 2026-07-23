**Time Complexity:** *O(H × W),* **Space Complexity:** *O(H × W).*

```cpp
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin>>H>>W;
    vector<vector<char>> a(H, vector<char>(W));
    for(auto &v: a) {
        for(char &x: v) cin>>x;
    }

    vector<vector<int>> dp(H, vector<int>(W, 0));
    dp[0][0] = 1;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            if(a[i][j]=='#') {
                continue;
            }
            if(i>0) {
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            }
            if(j>0) {
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
            }
        }
    }
    cout<<dp[H-1][W-1]<<"\n";
    return 0;
}
```