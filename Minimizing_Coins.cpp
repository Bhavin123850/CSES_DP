#include<bits/stdc++.h>
using namespace std;
#define int long long
int f(int index,int amount,vector<int>&coins,vector<vector<int>>&dp)
{
    int n = coins.size();
    if(amount == 0) return 0;
    if(index == n || amount < 0) return (int)1e8;
    if(dp[index][amount] != -1) return dp[index][amount];
    int mini = INT_MAX;
    mini = min(mini,f(index+1,amount,coins,dp));
    mini = min(mini,1 + f(index,amount-coins[index],coins,dp));
    return dp[index][amount] = mini;
}
signed main()
{
    int n,x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i = 0;i<n;i++)
    {
        cin>>coins[i];
    }
    // vector<vector<int>>dp(n+1,vector<int>(x+1,INT_MAX));
    // cout<<f(0,x,coins,dp);
    // for(int i = 0;i<=n;i++) dp[i][0] = 0;
    vector<int>curr(x+1,INT_MAX),next(x+1,INT_MAX);
    curr[0] = 0;
    next[0] = 0;
    for(int index = n-1;index>=0;index--)
    {
        for(int amount = 0;amount <= x;amount++)
        {
            int mini = INT_MAX;
            mini = min(mini,next[amount]);
            if(amount-coins[index] >= 0)
            mini = min(mini,1 + curr[amount-coins[index]]);
            curr[amount] = mini;
        }
        next = curr;
    }
    
    if(next[x] >= INT_MAX) cout<<-1<<"\n";
    else cout<<next[x]<<"\n";
    return 0;
}