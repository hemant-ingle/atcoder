**Time Complexity:** *O(N × W),* **Space Complexity:** *O(N × W).*

```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W;
    cin>>N>>W;
    vector<int> w(N), v(N);
    for(int i=0; i<N; i++) cin>>w[i]>>v[i];

    vector<vector<long long int>> dp(W+1, vector<long long int>(N+1, 0LL));
    for(int i=1; i<=W; i++) {
        for(int j=1; j<=N; j++) {
            dp[i][j] = dp[i][j-1];
            if(i>=w[j-1]) {
                dp[i][j] = max(dp[i][j], dp[i-w[j-1]][j-1] + v[j-1]);
            }
        }
    }
    cout<<dp[W][N]<<"\n";
    return 0;
}
```