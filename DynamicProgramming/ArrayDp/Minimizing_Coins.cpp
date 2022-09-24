#include <bits/stdc++.h>
#define mod 1e9+7
#define ll long long
using namespace std;
int main()
{
    ll n; cin>>n;
    ll tar; cin>>tar;
    vector<ll> coins;
    for(int i=0;i<n;i++){
        ll a; cin>>a;
        coins.push_back(a);
    }
    
    vector<ll> dp(tar+1,INT_MAX); //initialize all values with Max int value
    dp[0]=0;
    for(int i=1;i<=tar;i++){
        for(int j=0;j<coins.size();j++){
            if (i >= coins[j]){ //i must be greater equal to coins[j]
                dp[i] = min(dp[i],1+dp[i - coins[j]]); //taking min of current and 1+ (i-coins[j]) value
            }
        }
    }
    if (dp[tar] == INT_MAX){
        cout<<-1<<endl;
    }
    else
        cout<<dp[tar]<<endl;
    return 0;
}
// https://cses.fi/problemset/task/1634
