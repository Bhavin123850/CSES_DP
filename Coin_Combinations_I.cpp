#include<bits/stdc++.h>
using namespace std;
const int mod = (int)(1e9+7);
int f(int amount,vector<int>&coins,vector<int>&dp)
{
    if(amount < 0) return 0;
    if(amount == 0) return 1;
    if(dp[amount] != -1) return dp[amount];
    int count = 0;
    for(int index = 0;index<coins.size();index++)
    {
        count = (count%mod + f(amount-coins[index],coins,dp)%mod)%mod;
    }
    return dp[amount] = count;
}
int main()
{
    int n,x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i = 0;i<n;i++)
    {
        cin>>coins[i];
    }
    vector<int>dp(x+1,-1);
    cout<<f(x,coins,dp)<<"\n";
    return 0;
}