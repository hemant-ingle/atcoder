**Time Complexity:** *O(N × K),* **Space Complexity:** *O(N).*

```cpp
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int solve(int i, int K, vector<int> &h, vector<int> &dp) {
    if(i==0) return 0;
    if(dp[i] != INF) return dp[i];
    for(int j=1; j<=K; j++) {
        if(i>=j) {
            dp[i] = min(dp[i], solve(i-j, K, h, dp) + abs(h[i] - h[i-j]));
        }
    }
    return dp[i];
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin>>N>>K;
    vector<int> h(N);
    for(int &x: h) cin>>x;

    vector<int> dp(N, INF);
    int ans = solve(N-1, K, h, dp);
    cout<<ans<<"\n";
    return 0;
}
```