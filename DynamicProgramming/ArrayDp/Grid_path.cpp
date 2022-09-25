#include <bits/stdc++.h>
const int MOD = (int) 1e9 + 7;
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    vector<string> v;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    if (v[0][0] == '*' || v[n-1][n-1] == '*'){
        cout<<0<<endl;
        return 0;
    }
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (v[i-1][j-1] == '*') continue;
			if (i == 1 and j == 1) {
				dp[i][j] = 1;
			}
			else
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] ) % 1000000007;
		}
	}
    cout<<dp[n][n]<<endl;
    
}
// https://cses.fi/problemset/task/1638
