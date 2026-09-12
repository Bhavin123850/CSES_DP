#include<bits/stdc++.h>
using namespace std;
int f(int i,int j,vector<int>&a,vector<int>&b,vector<vector<int>>&dp)
{
    int n = a.size();
    int m = b.size();
    if(i == n || j == m) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int maxi = INT_MIN;
    if(a[i] == b[j])
    {
        maxi = max(maxi,1 + f(i+1,j+1,a,b,dp));
    }   
    else
    {
        maxi = max(maxi,max(f(i+1,j,a,b,dp),f(i,j+1,a,b,dp)));
    }
    return dp[i][j] = maxi;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    for(int i = 0;i<n;i++) cin>>a[i];
    for(int j = 0;j<m;j++) cin>>b[j];
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    for(int i = 0;i<=n;i++)
    {
        dp[i][m] = 0;
    }
    for(int j = 0;j<=m;j++)
    {
        dp[n][j] = 0;
    }
    for(int i = n-1;i>=0;i--)
    {
        for(int j = m-1;j>=0;j--)
        {
            int maxi = INT_MIN;
            if(a[i] == b[j])
            {
                maxi = max(maxi,1 + dp[i+1][j+1]);
            }
            else
            {
                maxi = max(maxi,max(dp[i+1][j],dp[i][j+1]));
            }
            dp[i][j] = maxi;
        }
    }
    cout<<dp[0][0]<<"\n";
    int i = 0,j = 0;
    while(i < n && j < m)
    {
        if(a[i] == b[j])
        {
            cout<<a[i]<<" ";
            i++,j++;
        }
        else
        {
            if(i+1 < n && dp[i][j] == dp[i+1][j])
            {
                i++;
            }
            else if(j+1 < m && dp[i][j] == dp[i][j+1])
            {
                j++;
            }
            else
            {
                break;
            }
        }
    }
    cout<<"\n";
    return 0;
}