#include<bits/stdc++.h>
using namespace std;

int solve(int N, int M, string &s, string &t, vector<vector<int>> &dp) {
    if(N==0 || M==0) return 0;
    if(dp[N][M] != -1) return dp[N][M];
    if(s[N-1] == t[M-1]) {
        dp[N][M] = solve(N-1, M-1, s, t, dp) + 1;
    } else {
        dp[N][M] = max(
            solve(N-1, M, s, t, dp),
            solve(N, M-1, s, t, dp)
        );
    }
    return dp[N][M];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t; cin>>s>>t;
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    int lcsSize = solve(n, m, s, t, dp);

    string lcs;
    for(int i=n, j=m; i>0 && j>0;) {
        if(s[i-1] == t[j-1]) {
            lcs.push_back(s[i-1]);
            i--;
            j--;
        } else if(solve(i-1, j, s, t, dp) >= solve(i, j-1, s, t, dp)) {
            i--;
        } else {
            j--;
        }
    }
    
    reverse(lcs.begin(), lcs.end());
    cout<<lcs<<"\n";
    return 0;
}