#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int frog_1(vector<int> &v, int i, vector<int> &dp)
{
if(i==0) return 0;
if(dp[i]!=-1) return dp[i];
int jump1=abs(v[i] - v[i-1]) + frog_1(v, i-1, dp);
int jump2=INT_MAX;
if(i>1) jump2=abs(v[i] - v[i-2]) + frog_1(v, i-2, dp);
dp[i]=min(jump1, jump2);
return dp[i];
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
int n;
cin>>n;
vector<int> v(n);
for(int &x: v) cin>>x;
vector<int> dp(n,-1);
int ans=frog_1(v,n-1,dp);
cout<<ans<<'\n';
return 0;
}