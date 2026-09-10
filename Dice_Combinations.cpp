#include<bits/stdc++.h>
using namespace std;
const int MOD = (int)(1e9+7);
int f(int amount,vector<int>&dp)
{
    if(amount < 0) return 0;
    if(amount == 0) return 1;
    if(dp[amount] != -1) return dp[amount];
    int count = 0;
    for(int i = 1;i<=6;i++)
    {
        count = (count%MOD + f(amount-i,dp)%MOD)%MOD;
    }
    return dp[amount] = count;
}
int main()
{
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    // cout<<f(n,dp)<<"\n";
    dp[0] = 1;
    for(int amount = 1;amount<=n;amount++)
    {
        int count = 0;
        for(int i = 1;i<=6;i++)
        {
            if(amount-i < 0) continue;
            count = (count%MOD + dp[amount-i]%MOD)%MOD;
        }
        dp[amount] = count;
    }
    cout<<dp[n]<<"\n";
    return 0;
}