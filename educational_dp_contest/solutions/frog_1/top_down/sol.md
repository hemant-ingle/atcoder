**Time Complexity:** *O(N),* **Space Complexity:** *O(N) (DP Array) + O(N) (recursion stack) = O(N).*

```cpp
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int frog_1(int N, vector<int> &h, vector<int> &dp) {
    if(N==0) return 0;
    if(N==1) return abs(h[1] - h[0]);
    if(dp[N] != INF) return dp[N];
    dp[N] = min(frog_1(N-1, h, dp) + abs(h[N] - h[N-1]),  frog_1(N-2, h, dp) + abs(h[N] - h[N-2]));
    return dp[N];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N;
    vector<int> h(N);
    for(int &x: h) cin>>x;

    vector<int> dp(N, INF);
    int ans = frog_1(N-1, h, dp);
    cout<<ans<<"\n";
    return 0;
}
```