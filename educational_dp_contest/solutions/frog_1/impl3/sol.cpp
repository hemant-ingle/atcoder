#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N; cin>>N;
    vector<int> h(N);
    for(int &x: h) cin>>x;

    vector<int> dp(N+1, INT_MAX);
    dp[0] = dp[1] = 0;
    for(int i=2; i<=N; i++)
    {
        dp[i] = dp[i-1] + abs(h[i-1] - h[i-2]);
        if(i>2) {
            dp[i] = min(dp[i], dp[i-2] + abs(h[i-1] - h[i-3]));
        }
    }

    cout<<dp[N]<<"\n";
    return 0;
}