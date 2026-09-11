#include<bits/stdc++.h>
using namespace std;
const int mod = (int)(1e9+7);
const int max_n = 1e6;
long long dp[max_n + 1][2];
int main()
{
    int tt;
    cin>>tt;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i = 2;i<=max_n;i++)
    {
        dp[i][0] = (4*dp[i-1][0]%mod + dp[i-1][1]%mod)%mod;
        dp[i][1] = (2*dp[i-1][1]%mod + dp[i-1][0]%mod)%mod;
    }
    while(tt--)
    {
        int n;
        cin>>n;
        cout<<(dp[n][0]%mod + dp[n][1]%mod)%mod<<"\n";
    }
    return 0;
}