**Time Complexity:** *O(N × W),* **Space Complexity:** *O(N × W).*

```cpp
#include<bits/stdc++.h>
using namespace std;

long long int solve(int N, int W, vector<int> &w, vector<int> &v, vector<vector<long long int>> &dp) {
    if(N==0 || W==0) return 0;
    if(dp[N][W] != -1) return dp[N][W];
    dp[N][W] = solve(N-1, W, w, v, dp);
    if(W >= w[N-1]) {
        dp[N][W] = max(dp[N][W], solve(N-1, W-w[N-1], w, v, dp) + v[N-1]);
    }
    return dp[N][W];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W; cin>>N>>W;
    vector<int> w(N), v(N);
    for(int i=0; i<N; i++) cin>>w[i]>>v[i];

    vector<vector<long long int>> dp(N+1, vector<long long int>(W+1, -1));
    long long int ans = solve(N, W, w, v, dp);
    cout<<ans<<"\n";
    return 0;
}
```