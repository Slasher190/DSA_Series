#include <bits/stdc++.h>
#define ll long long 
#define mod 1e9+7
using namespace std;
 
int main(){
    int n,tar;
    cin>>n>>tar;
    vector<int> coins;
    for(int i=0;i<n;i++){
        int a; cin>>a;
        coins.push_back(a);
    }
    ll MOD = (ll)(mod);
    vector<int> dp(tar+1,0);
    dp[0] = 1;
    for(int i=1;i<=tar;i++){
        for(int j=0;j<coins.size();j++){
            if (i >= coins[j]){
                dp[i] = dp[i] + dp[i-coins[j]];
                dp[i] = dp[i]%MOD;
            }
        }
    }
    cout<<dp[tar]%MOD<<endl;
}
// https://cses.fi/problemset/task/1635
