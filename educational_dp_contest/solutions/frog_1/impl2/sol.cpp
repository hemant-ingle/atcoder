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
    dp[1] = abs(h[1] - h[0]);
    for(int i=2; i<N; i++)
    {
        dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
    }

    cout<<dp[N-1]<<"\n";
    return 0;
}