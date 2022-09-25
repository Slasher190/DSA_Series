#include <bits/stdc++.h>
const int MOD = (int) 1e9 + 7;
using namespace std;
 
int main()
{
    int n,tar;
    cin>>n>>tar;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<int> dp(tar+1,0);
    dp[0]=1;
    
    for(int i=1;i<=coins.size();i++){
        for(int coin=0;coin<=tar;coin++){
            if (coin >= coins[i-1]){
                dp[coin] += dp[coin - coins[i-1]]; // adding all possible combinations to make value from 1 to total value
                dp[coin] %= MOD;
            }
        }
    }
    cout<<dp[tar]<<endl;
}
// https://cses.fi/problemset/result/4687295/
