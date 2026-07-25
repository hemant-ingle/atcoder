**Time Complexity:** *O(N × ΣV),* **Space Complexity:** *O(N × ΣV).*

```cpp
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int solve(int N, int V, vector<int> &w, vector<int> &v, vector<vector<int>> &dp) {
    if(N==0) return V==0 ? 0 : INF;
    if(dp[N][V] != -1) return dp[N][V];
    dp[N][V] = solve(N-1, V, w, v, dp);
    if(V >= v[N-1]) {
        dp[N][V] = min(dp[N][V], solve(N-1, V - v[N-1], w, v, dp) + w[N-1]);
    }
    return dp[N][V];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W; cin>>N>>W;
    vector<int> w(N), v(N);
    for(int i=0; i<N; i++) cin>>w[i]>>v[i];
    const int MAX_VALUE = accumulate(v.begin(), v.end(), 0);

    vector<vector<int>> dp(N+1, vector<int>(MAX_VALUE+1, -1));
    solve(N, MAX_VALUE, w, v, dp);

    int ans=0;
    for(int val=MAX_VALUE; val>=0; val--) {
        if(solve(N, val, w, v, dp) <= W) {
            ans = val;
            break;
        }
    }

    cout<<ans<<"\n";
    return 0;
}
```