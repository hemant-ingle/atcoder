**Time Complexity:** *O(n),* **Space Complexity:** *O(n).*

```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N; cin>>N;
    vector<int> h(N);
    for(int &x: h) cin>>x;

    vector<int> dp(N, INT_MAX);
    dp[0] = 0;
    for(int i=1; i<N; i++)
    {
        dp[i] = dp[i-1] + abs(h[i] - h[i-1]);
        if(i>1) {
            dp[i] = min(dp[i], dp[i-2] + abs(h[i] - h[i-2]));
        }
    }

    cout<<dp[N-1]<<"\n";
    return 0;
}
```