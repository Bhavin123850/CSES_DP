#include<bits/stdc++.h>
using namespace std;
#define int long long
int f(int number,vector<int>&dp)
{
    if(number == 0ll) return 0ll;
    if(number < 0ll) return INT_MAX;
    if(dp[number] != -1) return dp[number];
    int temp = number;
    int mini = INT_MAX;
    while(temp > 0)
    {
        int digit = temp%10;
        temp /= 10;
        if(digit == 0) continue;
        int val = f(number-digit,dp);
        if(val != INT_MAX)
        mini = min(mini,1ll + val);
    }
    return dp[number] = mini;
}
signed main()
{
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    cout<<f(n,dp)<<"\n";
    return 0;
}