#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W; cin>>N>>W;
    vector<int> w(N), v(N);
    for(int i=0; i<N; i++) cin>>w[i]>>v[i];
    const int MAX_VALUE = accumulate(v.begin(), v.end(), 0);

    vector<int> dp(MAX_VALUE+1, INF);
    dp[0] = 0;
    for(int i=0; i<N; i++) {
        for(int val=MAX_VALUE; val>=v[i]; val--) {
            dp[val] = min(dp[val], dp[val-v[i]] + w[i]);
        }
    }

    int ans=0;
    for(int val=MAX_VALUE; val>=0; val--) {
        if(dp[val] <= W) {
            ans = val;
            break;
        }
    }

    cout<<ans<<"\n";
    return 0;
}