#include<bits/stdc++.h>
using namespace std;
#define mod (int)(1e9+7)
bool check(int i,int j,int n,int m)
{
    if(i < 0 || j < 0 || i >= n || j >= m) return false;
    return true;
}
int f(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&dp)
{
    int n = grid.size();
    int m = grid[0].size();
    if(i == n-1 && j == n-1) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    int count = 0;
    if(check(i+1,j,n,m) && grid[i+1][j] == '.')
    {
        count = (count%mod + f(i+1,j,grid,dp)%mod)%mod;
    }
    if(check(i,j+1,n,m) && grid[i][j+1] == '.')
    {
        count = (count%mod + f(i,j+1,grid,dp)%mod)%mod;
    }
    return dp[i][j] = count;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<char>>grid(n,vector<char>(n));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }
    if(grid[0][0] == '*' || grid[n-1][n-1] == '*')
    {
        cout<<0<<"\n";
        return 0;
    }
    vector<vector<int>>dp(n,vector<int>(n,-1));
    cout<<f(0,0,grid,dp)<<"\n";
    return 0;
}