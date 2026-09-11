#include<bits/stdc++.h>
using namespace std;
const int mod = (int)(1e9+7);
int f(int index,int amount,vector<int>&coins,vector<vector<int>>&dp)
{
    int n = coins.size();
    if(amount == 0) return 1;
    if(index == n) return 0;
    if(amount < 0) return 0;
    if(dp[index][amount] != -1) return dp[index][amount];
    int count = 0;
    count = count%mod + f(index,amount-coins[index],coins,dp)%mod;
    count = count%mod + f(index+1,amount,coins,dp)%mod;
    return dp[index][amount] = count;
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
    vector<int>next(x+1,0);
    next[0] = 1;
    vector<int>curr(x+1,0);
    curr[0] = 1;
    for(int index = n-1;index>=0;index--)
    {
        for(int amount = 0;amount<=x;amount++)
        {
            int count = 0;
            if(amount-coins[index] >= 0)
            count = (count%mod + curr[amount-coins[index]]%mod)%mod;
            count = (count%mod + next[amount]%mod)%mod;
            curr[amount] = count;
        }
        next = curr;
    }
    cout<<next[x]<<"\n";
    return 0;
}