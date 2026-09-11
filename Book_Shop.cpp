#include<bits/stdc++.h>
using namespace std;
int f(int index,int amount,vector<int>&price,vector<int>&pages,vector<vector<int>>&dp)
{
    int n = pages.size();
    if(index == n) return 0;
    if(dp[index][amount] != -1) return dp[index][amount];
    int maxi = INT_MIN;
    if(amount-price[index] >= 0)
    maxi = max(maxi,pages[index] + f(index+1,amount-price[index],price,pages,dp));
    maxi = max(maxi,f(index+1,amount,price,pages,dp));
    return dp[index][amount] = maxi;
}
int main()
{
    int n,x;
    cin>>n>>x;
    vector<int>price(n),pages(n);
    for(int i = 0;i<n;i++)
    {
        cin>>price[i];
    }
    for(int i = 0;i<n;i++)
    {
        cin>>pages[i];
    }
    vector<int>next(x+1,0),curr(x+1,0);
    for(int index = n-1;index >= 0;index--)
    {
        for(int amount = 0;amount<=x;amount++)
        {
            int maxi = INT_MIN;
            if(amount-price[index] >= 0)
            {
                maxi = max(maxi,pages[index]+next[amount-price[index]]);
            }
            maxi = max(maxi,next[amount]);
            curr[amount] = maxi;
        }
        next = curr;
    }
    cout<<next[x]<<"\n";
    return 0;
}