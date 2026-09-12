#include<bits/stdc++.h>
using namespace std;
int f(int i,int j,string s,string t,vector<vector<int>>&dp)
{
    int n = s.length();
    int m = t.length();
    if(i == n)
    {
        return (m-j);
    }
    if(j == m)
    {
        return (n-i);
    }
    int mini = INT_MAX;
    if(s[i] == t[j])
    {
        mini = min(mini,f(i+1,j+1,s,t,dp));
    }
    else
    {
        mini = min(mini,1 + f(i+1,j,s,t,dp));
        mini = min(mini,1 + f(i+1,j+1,s,t,dp));
        mini = min(mini,1 + f(i,j+1,s,t,dp));
    }
    return dp[i][j] = mini;
}
int main()
{
    string s,t;
    cin>>s>>t;
    int n = s.length();
    int m = t.length();
    // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    // for(int i = 0;i<=n;i++)
    // {
    //     dp[i][m] = n-i;
    // }
    // for(int j = 0;j<=m;j++)
    // {
    //     dp[n][j] = m-j;
    // }
    vector<int>next(m+1),curr(m+1);
    for(int j = 0;j<=m;j++) next[j] = m-j;
    for(int i = n-1;i>=0;i--)
    {
        curr[m] = n-i;
        for(int j = m-1;j>=0;j--)
        {
            int mini = INT_MAX;
            if(s[i] == t[j])
            {
                mini = min(mini,next[j+1]);
            }
            else
            {
                mini = min(mini,1 + next[j]);
                mini = min(mini,1 + next[j+1]);
                mini = min(mini,1 + curr[j+1]);
            }
            curr[j] = mini;
        }
        next = curr;
    }
    cout<<next[0]<<"\n";
    return 0;
}