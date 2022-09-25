
// Using 0/1 knapsack for calculating max weight

#include <bits/stdc++.h>
const int MOD = (int) 1e9 + 7;
using namespace std;
int main()
{
    int n,tot;
    cin>>n>>tot;
    
    std::vector<int> price(n,0);
    vector<int> pages(n,0);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(tot+1,0));
    for (int i=1;i<=n;i++){
        for(int j=1;j<=tot;j++){
            if (price[i-1] <= j){
                dp[i][j] = max(pages[i-1]+dp[i-1][j - price[i-1]],dp[i-1][j]); // choices
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][tot]<<endl;
    
}

// https://cses.fi/problemset/task/1158
