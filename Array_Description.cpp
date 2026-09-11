#include<bits/stdc++.h>
using namespace std;
const int mod = (int)(1e9+7);
int f(int index,int prev,vector<int>&v,vector<vector<int>>&dp,int &m)
{
    int n = v.size();
    if(index == n) return 1;
    if(dp[index][prev+1] != -1) return dp[index][prev+1];
    int count = 0;
    if(index == 0)
    {       
        if(v[index] == 0)
        {
            if(prev == -1)
            {
                for(int i = 1;i<=m;i++)
                {
                    count = (count%mod + f(index+1,i,v,dp,m)%mod)%mod;
                }
            }
        }
        else
        {
            count = (count%mod + f(index+1,v[index],v,dp,m)%mod)%mod;
        }
    }
    else
    {
        if(v[index] == 0)
        {
            if(prev+1 < m+1)
            count = (count%mod + f(index+1,prev+1,v,dp,m)%mod)%mod;
            if(prev-1 > 0)
            count = (count%mod + f(index+1,prev-1,v,dp,m)%mod)%mod;
            count = (count%mod + f(index+1,prev,v,dp,m)%mod)%mod;
        }
        else
        {   
            if(abs(v[index]-prev) <= 1)
            {
                count = (count%mod + f(index+1,v[index],v,dp,m)%mod)%mod;
            }
        }
    }
    return dp[index][prev+1] = count;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    for(int i = 0;i<n;i++)
    {
        cin>>v[i];
    }
    if(n == 1)
    {
        if(v[0] == 0)
        {
            cout<<m<<"\n";
        }
        else
        {
            cout<<1<<"\n";
        }
        return 0;
    }
    vector<vector<int>>dp(n,vector<int>(m+2,-1));
    cout<<f(0,-1,v,dp,m)<<"\n";
    return 0;
}