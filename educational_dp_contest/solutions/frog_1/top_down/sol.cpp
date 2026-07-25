#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int solve(int i, vector<int> &h, vector<int> &dp) {
    if(i==0) return 0;
    if(i==1) return abs(h[1] - h[0]);
    if(dp[i] != INF) return dp[i];
    return dp[i] = min(
        solve(i-1, h, dp) + abs(h[i] - h[i-1]),  
        solve(i-2, h, dp) + abs(h[i] - h[i-2])
    );
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N;
    vector<int> h(N);
    for(int &x: h) cin>>x;

    vector<int> dp(N, INF);
    int ans = solve(N-1, h, dp);
    cout<<ans<<"\n";
    return 0;
}