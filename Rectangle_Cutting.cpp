#include<bits/stdc++.h>
using namespace std;
int f(int a,int b,vector<vector<int>>&dp)
{
    if(a == b) return 0;
    // if(a == 1) return b-1;
    // if(b == 1) return a-1;
    if(dp[a][b] != -1) return dp[a][b];
    int mini = INT_MAX;
    if(a > 1)
    {
        for(int i = 1;i<a;i++)
        {
            int left_a = i;
            int left_b = b;
            int right_a = a-i;
            int right_b = b;
            int count = 0;
            count = count + f(left_a,left_b,dp);
            count = count + f(right_a,right_b,dp);
            mini = min(mini,1 + count);
        }
    }
    if(b > 1)
    {
        for(int i = 1;i<b;i++)
        {
            int up_a = a;
            int up_b = i;
            int down_a = a;
            int down_b = b-i;
            int count = 0;
            count = count + f(up_a,up_b,dp);
            count = count + f(down_a,down_b,dp);
            mini = min(mini,1 + count);
        }
    }
    return dp[a][b] = mini;
}
int main()
{
    int x,y;
    cin>>x>>y;
    vector<vector<int>>dp(x+1,vector<int>(y+1,-1));
    for(int i = 0;i<=min(x,y);i++) dp[i][i] = 0;
    for(int a = 1;a<=x;a++)
    {
        for(int b = 1;b<=y;b++)
        {
            if(a == b) continue;
            if(a == 1)
            {
                dp[a][b] = b-1;
                continue;
            }
            if(b == 1)
            {
                dp[a][b] = a-1;
                continue;
            }
            int mini = INT_MAX;
            if(a > 1)
            {
                for(int i = 1;i<a;i++)
                {
                    int left_a = i;
                    int left_b = b;
                    int right_a = a-i;
                    int right_b = b;
                    int count = 0;
                    count = count + dp[left_a][left_b];
                    count = count + dp[right_a][right_b];
                    mini = min(mini,1 + count);
                }
            }
            if(b > 1)
            {
                for(int i = 1;i<b;i++)
                {
                    int up_a = a;
                    int up_b = i;
                    int down_a = a;
                    int down_b = b-i;
                    int count = 0;
                    count = count + dp[up_a][up_b];
                    count = count + dp[down_a][down_b];
                    mini = min(mini,1 + count);
                }
            }
            dp[a][b] = mini;
        }
    }
    cout<<dp[x][y]<<"\n";
    return 0;
}