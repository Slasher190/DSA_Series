#include <bits/stdc++.h>
#define mod 1e9+7
#define ll long long
using namespace std;
int main()
{
    ll n; cin>>n;
    vector<ll> dp(n+1,0);
    dp[0]=1;dp[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=6;j++){
            if (i >= j){ // for all only if i >= coins value
                dp[i] = dp[i] % (ll)(mod) + dp[i-j] % (ll)(mod); // sum of all possible way
            }
            else{
                break;
            }
        }
    }
    cout<<dp[n]% (ll)(mod)<<endl;
    return 0;
}
// https://cses.fi/problemset/task/1633
